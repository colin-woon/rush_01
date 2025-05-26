/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 15:42:13 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
bool	is_solve(t_data *data);
void	backtracking(t_data *data);
bool	is_grid_full_base_case(t_data *data, int row, int col, bool *is_found);

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
	static bool	found_solution = false;

	if (is_grid_full_base_case(data, data->row, data->col, &found_solution))
		return (true);
	backtracking(data);
	if (found_solution)
		return (true);
	decrement_grid_index(data, &data->row, &data->col);
	return(false);
}

void	backtracking(t_data *data)
{
	int			to_check;

	to_check = data->highest + 1;
	while (--to_check >= 0)
	{
		if (data->grid[data->row][data->col].is_fixed)
		{
			if (!is_valid_then_move(data))
			continue;
			if (is_solve(data))
				break ;
			else
				continue;
		}
		data->grid[data->row][data->col].value = to_check;
		if (is_duplicate(data, to_check, data->row, data->col))
			continue;
		if (!is_valid_then_move(data))
			continue;
		if (is_solve(data))
			break;
	}
}

bool	is_grid_full_base_case(t_data *data, int row, int col, bool *is_found)
{
	if (row == data->highest && col == data->highest)
	{
		(*is_found) = true;
		return (true);
	}
	return (false);
}
