/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 03:53:40 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
void	print_grid(t_data *data);
bool	is_duplicate(t_data *data, t_recursion_var var, int row, int col);
bool	is_duplicate_row(t_data *data, int to_check, const int fix, int i_cur);
bool	is_duplicate_col(t_data *data, int to_check, const int fix, int i_cur);
void	init_validation_vars(t_validation *var, t_data *data, e_from dir, int fix);
bool is_valid_from_right(t_data *data, const int clue, const int fix);
bool is_valid_from_left(t_data *data, const int clue, const int fix);
bool is_valid_from_bottom(t_data *data, const int clue, const int fix);
bool is_valid_from_top(t_data *data, const int clue, const int fix);
bool	is_valid_col(t_data *data, const int i_clue);
bool	is_valid_row(t_data *data, const int i_clue);
bool	is_solve(t_data *data);
void	decrement_grid_index(t_data *data, int *row, int* col);
void	increment_grid_index(t_data *data, int *row, int* col);

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("hello\n");
		exit(EXIT_FAILURE);
	}
	parse(&data, av);
	prune_solution(&data);
	if (is_solve(&data))
	{
		ft_putstr("solution found");
		print_grid(&data);
	}
	else
		ft_putstr("No solution found");
}

void	prune_solution(t_data *data)
{
	fill_corners(data);
	fill_edges(data);
}

void	print_grid(t_data *data)
{
	int		row;
	int		col;
	char	number;

	row = 0;
	while (row < data->highest)
	{
		col = 0;
		while (col < data->highest)
		{
			number = ft_itoa(data->grid[row][col].value);
			write(1, &number, 1);
			write(1, " ", 1);
			col++;
		}
		ft_putstr("\n");
		row++;
	}
	// ft_putstr("\n");
}

bool	is_solve(t_data *data)
{
	t_recursion_var var;
	// var.row = i_row;
	// var.col = i_col;
	// var.new_row = i_row;
	// var.new_col = i_col;
	var.to_check = data->highest + 1;
	static bool	found_solution = false;
	static int	row = 0;
	static int	col = 0;
	// static int loops = 0;

	if (row == data->highest && col == data->highest)
	{
		found_solution = true;
		return (true);
	}
	// if (loops == 25)
	// 	exit(0);
	// loops++;
	while (--var.to_check >= 0)
	{
		// printf("row: %d ", row);
		// printf("col: %d ", col);
		// printf("data_end: %d\n", data->end);

		if (data->grid[row][col].is_fixed)
		{
			if (col == data->end)
			{
				if (!is_valid_row(data, row))
					continue;
			}
			if (row == data->end)
			{
				if (!is_valid_col(data, col))
					continue;
			}
			increment_grid_index(data, &row, &col);
			if (is_solve(data))
				break ;
			else
				continue;
		}
		data->grid[row][col].value = var.to_check;
		// print_grid(data);
		if (!is_duplicate(data, var, row, col))
		{
			print_grid(data);
			// printf("row: %d ", row);
			// printf("col: %d ", col);
			// printf("data_end: %d\n", data->end);
			// printf("\n");
			if (col == data->end)
			{
				if (!is_valid_row(data, row))
					continue;
			}
			if (row == data->end)
			{
				if (!is_valid_col(data, col))
					continue;
			}
			increment_grid_index(data, &row, &col);
			if (is_solve(data))
				break ;
		}
	}
	if (found_solution)
		return (true);
	decrement_grid_index(data, &row, &col);
	return(false);
}
void	increment_grid_index(t_data *data, int *row, int* col)
{
	if ((*col) == data->end)
	{
		if ((*row) == data->end)
		{
			(*row) = data->highest;
			(*col) = data->highest;
			return ;
		}
		(*col) = 0;
		(*row) += 1;
	}
	else
		(*col)++;
}

void	decrement_grid_index(t_data *data, int *row, int* col)
{
	if ((*col) == 0)
	{
		if ((*row) == 0)
			return ;
		(*col) = data->end;
		(*row) -= 1;
	}
	else
		(*col)--;
}

bool	is_valid_row(t_data *data, const int i_clue)
{
	// printf("RUNNING is valid row   ");
	if (is_valid_from_left(data, data->row_left[i_clue], i_clue) \
	 && is_valid_from_right(data, data->row_right[i_clue], i_clue))
		return (true);
	return (false);
}

bool	is_valid_col(t_data *data, const int i_clue)
{
	if (is_valid_from_top(data, data->col_up[i_clue], i_clue) \
	 && is_valid_from_bottom(data, data->col_down[i_clue], i_clue))
		return (true);
	return (false);
}

bool is_valid_from_top(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, TOP, fix);
	while (var.i <= data->end)
	{
		if (data->grid[var.i][fix].value == data->highest)
		{
			if (var.i != 0)
				var.can_see++;
			break ;

		}
		if (var.cur_max < data->grid[var.i][fix].value)
		{
			var.cur_max =  data->grid[var.i][fix].value;
			var.can_see++;
		}
		var.i++;
	}
	if (clue == var.can_see)
		return (true);
	return (false);
}

bool is_valid_from_bottom(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, BOTTOM, fix);
	while (var.i >= 0)
	{
		if (data->grid[var.i][fix].value == data->highest)
		{
			if (var.i != data->end)
				var.can_see++;
			break ;

		}
		if (var.cur_max < data->grid[var.i][fix].value)
		{
			var.cur_max =  data->grid[var.i][fix].value;
			var.can_see++;
		}
		var.i--;
	}
	if (clue == var.can_see)
		return (true);
	return (false);
}

bool is_valid_from_left(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, LEFT, fix);
	// printf("var i %d ", var.i);
	// printf("clue %d ", clue);
	// printf("fix %d", fix);
	while (var.i <= data->end)
	{
		if (data->grid[fix][var.i].value == data->highest)
		{
			if (var.i != 0)
				var.can_see++;
			break ;
		}
		if (var.cur_max < data->grid[fix][var.i].value)
		{
			var.cur_max =  data->grid[fix][var.i].value;
			var.can_see++;
		}
		var.i++;
	}
	// printf("can see %d\n", var.can_see);
	if (clue == var.can_see)
	{
		// printf("true from left");
		return (true);
	}
	return (false);
}

bool is_valid_from_right(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, RIGHT, fix);
	while (var.i >= 0)
	{
		if (data->grid[fix][var.i].value == data->highest)
		{
			if (var.i != data->end)
				var.can_see++;
			break ;
		}
		if (var.cur_max < data->grid[fix][var.i].value)
		{
			var.cur_max =  data->grid[fix][var.i].value;
			var.can_see++;
		}
		var.i--;
	}
	if (clue == var.can_see)
	{
		printf("true from right");
		return (true);
	}
	return (false);
}

void	init_validation_vars(t_validation *var, t_data *data, e_from dir, int fix)
{
	var->can_see = 1;
	if (dir == TOP)
	{
		var->cur_max = data->grid[0][fix].value;
		var->i = 0;
	}
	else if (dir == BOTTOM)
	{
		var->cur_max = data->grid[data->end][fix].value;
		var->i = data->end;
	}
	else if (dir == LEFT)
	{
		var->i = 0;
		var->cur_max = data->grid[fix][0].value;
	}
	else if (dir == RIGHT)
	{
		var->i = data->end;
		var->cur_max = data->grid[fix][data->end].value;
	}

}

bool	is_duplicate_col(t_data *data, int to_check, const int fix, int i_cur)
{
	int	i;

	i = -1;
	while(++i <= data->end)
	{
		if (i == i_cur)
			continue;
		if (to_check == data->grid[i][fix].value)
			return (true);
	}
	return (false);
}

bool	is_duplicate_row(t_data *data, int to_check, const int fix, int i_cur)
{
	int	i;

	i = -1;
	while(++i <= data->end)
	{
		// printf("i dup %d\n", i);
		// printf("i cur %d to_check %d\n", i_cur, to_check);
		// printf("\n");
		if (i == i_cur)
			continue;
		if (to_check == data->grid[fix][i].value)
			return (true);
	}
	return (false);
}

bool	is_duplicate(t_data *data, t_recursion_var var, int row, int col)
{
	if (is_duplicate_col(data, var.to_check, col, row) \
	|| is_duplicate_row(data, var.to_check, row, col))
		return (true);
	return (false);
}
