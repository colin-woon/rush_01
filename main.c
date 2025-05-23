/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 20:15:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
void	print_grid(t_data *data);
bool	is_repeated_list(t_data *data, int row, int col, bool is_row);
bool	is_valid_from_top(t_data *data, int initial_value, int nth_col);
void	backtracking(t_data *data);
void	init_validation_vars(t_validation *var);

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
	data->grid[0][data->end].value = 1;
	data->grid[1][data->end].value = 5;
	data->grid[2][data->end].value = 3;
	print_grid(data);
	if (is_valid_from_top(data, data->col_up[data->end], data->end))
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

bool is_valid_from_top(t_data *data, int initial_value, int nth)
{
	t_validation var;

	init_validation_vars(&var);
	while (var.i < data->end)
	{
		var.j = var.i + 1;
		while (var.j <= data->end)
		{
			if (data->grid[var.i][nth].value == data->grid[var.j][nth].value)
				return (false);
			if (data->grid[var.i][nth].value < data->grid[var.j][nth].value && var.i == 0)
			{
				var.can_see++;
				// printf("can_see %d\n", var.can_see);
			}
			else if (data->grid[var.i][nth].value > data->grid[var.j][nth].value && var.i != 0)
				var.can_see--;
			var.j++;
		}
		var.i++;
	}
	printf("initial_value %d\n", initial_value);
	printf("can_see %d\n", var.can_see);
	if (initial_value == var.can_see)
		return (true);
	return (false);
}

void	init_validation_vars(t_validation *var)
{
	var->i = 0;
	var->j = 0;
	var->can_see = 1;
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
