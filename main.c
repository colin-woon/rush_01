/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:07 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 18:42:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	prune_solution(t_data *data);
void	print_grid(t_data *data);

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
	fill_edges(data);
	print_grid(data);
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

