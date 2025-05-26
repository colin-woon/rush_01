/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 14:26:03 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
bool	is_solve(t_data *data);

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(EXIT_FAILURE);
	parse(&data, av);
	prune_solution(&data);
	if (is_solve(&data))
		print_grid(&data);
	else
		ft_putstr("No solution found");
}

void	prune_solution(t_data *data)
{
	fill_corners(data);
	fill_edges(data);
}

bool	is_solve(t_data *data)
{
	int			to_check;
	static bool	found_solution = false;
	static int	row = 0;
	static int	col = 0;

	to_check = data->highest + 1;
	if (row == data->highest && col == data->highest)
	{
		found_solution = true;
		return (true);
	}
	while (--to_check >= 0)
	{
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
		data->grid[row][col].value = to_check;
		if (!is_duplicate(data, to_check, row, col))
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
		}
	}
	if (found_solution)
		return (true);
	decrement_grid_index(data, &row, &col);
	return(false);
}


