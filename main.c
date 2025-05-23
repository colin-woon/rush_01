/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 18:19:43 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
void	print_grid(t_data *data);
void	fill_corners(t_data *data);

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
}

void	prune_solution(t_data *data)
{
	fill_corners(data);
	print_grid(data);
	// fill_edges(data, av);
}

void	fill_corners(t_data *data)
{
	if (data->col_up[0] == 1 && data->row_left[0] == 1)
	{
		data->grid[0][0].value = data->highest;
		data->grid[0][0].is_fixed = true;
	}
	if (data->col_up[data->end] == 1 && data->row_right[0] == 1)
	{
		data->grid[0][data->end].value = data->highest;
		data->grid[0][data->end].is_fixed = true;
	}
	if (data->col_down[0] == 1 && data->row_left[data->end] == 1)
	{
		data->grid[data->end][0].value = data->highest;
		data->grid[data->end][0].is_fixed = true;
	}
	if (data->col_down[data->end] == 1 && data->row_right[data->end] == 1)
	{
		data->grid[data->end][data->end].value = data->highest;
		data->grid[data->end][data->end].is_fixed = true;
	}
}

// void	fill_edges(t_data *data, char **av)

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
