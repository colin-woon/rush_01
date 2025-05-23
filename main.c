/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/24 00:46:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
void	print_grid(t_data *data);
bool	is_repeated_list(t_data *data, int row, int col, bool is_row);
bool	is_valid_from_top(t_data *data, int initial_value, int col);
void	backtracking(t_data *data);
void	init_validation_vars_back(t_validation *var, t_data *data, e_from dir, int i);
void	init_validation_vars_front(t_validation *var, t_data *data, e_from dir, int i);
bool	is_duplicate_col(t_data *data, int to_check, int i, int col);


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
	// backtracking(&data);
}

void	prune_solution(t_data *data)
{
	fill_corners(data);
	// fill_edges(data);
	data->grid[0][data->end].value = 4;
	data->grid[1][data->end].value = 2;
	data->grid[2][data->end].value = 1;
	data->grid[3][data->end].value = 4;
	print_grid(data);
	if (is_valid_from_top(data, data->col_up[data->end], data->end))
	// && is_valid_from_bottom(data, data->col_down[data->end], data->end))
		printf("works\n");
	else
		printf("found invalid\n");
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
}

bool is_valid_from_top(t_data *data, int initial_value, int col)
{
	t_validation var;

	init_validation_vars_front(&var, data, TOP, col);
	while (var.i <= data->end)
	{
		if (is_duplicate_col(data, data->grid[var.i][col].value, var.i, col))
			return (false);
		if (data->grid[var.i][col].value == data->highest)
		{
			if (var.i != 0)
				var.can_see++;
			break ;
		}
		if (var.cur_max < data->grid[var.i][col].value)
		{
			var.cur_max =  data->grid[var.i][col].value;
			var.can_see++;
		}
		var.i++;
	}
	if (initial_value == var.can_see)
		return (true);
	return (false);
}

void	init_validation_vars_front(t_validation *var, t_data *data, e_from dir, int i)
{
	var->i = 0;
	var->j = 0;
	var->can_see = 1;
	if (dir == TOP)
		var->cur_max = data->grid[0][i].value;
	else if (dir == BOTTOM)
		var->cur_max = data->grid[data->end][i].value;
}

void	init_validation_vars_back(t_validation *var, t_data *data, e_from dir, int i)
{
	var->i = data->end;
	var->j = data->end;
	var->can_see = 1;
	if (dir == LEFT)
		var->cur_max = data->grid[i][0].value;
	else if (dir == RIGHT)
		var->cur_max = data->grid[i][data->end].value;
}

bool	is_duplicate_col(t_data *data, int to_check, int i, int col)
{
	while(i + 1 <= data->end)
	{
		if (to_check == data->grid[i + 1][col].value)
			return (true);
		i++;
	}
	return (false);
}

// void	backtracking(t_data *data)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	col = 0;
// 	while (row < data->end)
// 	{

// 		while(col < data->end)
// 		{
// 			col++;
// 		}
// 		row++;
// 	}
// }
