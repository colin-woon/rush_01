/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:24:01 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 16:28:02 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	print_grid(t_data *data);
void	decrement_grid_index(t_data *data, int *row, int *col);
void	increment_grid_index(t_data *data, int *row, int *col);

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

void	increment_grid_index(t_data *data, int *row, int *col)
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

void	decrement_grid_index(t_data *data, int *row, int *col)
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
