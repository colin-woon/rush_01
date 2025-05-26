/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:46:31 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 14:05:55 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	parse_array(int **array, int highest, char **av, int start);
void	parse(t_data *data, char **av);
void	init_grid(t_data *data);
int		get_highest(char **av);

void	parse(t_data *data, char **av)
{
	data->highest = get_highest(av);
	data->end = data->highest - 1;
	data->grid = malloc(data->highest * sizeof(t_cell *));
	init_grid(data);
	parse_array(&data->col_up, data->highest, av, 0);
	parse_array(&data->col_down, data->highest, av, data->highest);
	parse_array(&data->row_left, data->highest, av, 2 * data->highest);
	parse_array(&data->row_right, data->highest, av, 3 * data->highest);
}

int	get_highest(char **av)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (av[1][i])
	{
		if(av[1][i] == ' ')
		{
			i++;
			continue;
		}
		if (av[1][i] >= '1' && av[1][i] <= '9')
			result++;
		i++;
	}
	if (result % 4 != 0)
	{
		ft_putstr("Error: Not a grid\n");
		exit(EXIT_FAILURE);
	}
	return (result / 4);
}

void	parse_array(int **array, int highest, char **av, int start)
{
	int	i;
	int	number;
	int	array_len;

	i = 0;
	number = 0;
	array_len = 0;
	*array = malloc((highest + 1) * sizeof(int));
	while (array_len < highest)
	{
		if (av[1][i] == ' ')
		{
			i++;
			continue;
		}
		if (number >= start)
		{
			(*array)[array_len] = ft_atoi(av[1][i]);
			array_len++;
		}
		number++;
		i++;
	}
	(*array)[array_len] = -1;
}

void	init_grid(t_data *data)
{
	int	row;
	int	column;

	row = 0;
	while (row < data->highest)
	{
		data->grid[row] = malloc(data->highest * sizeof(t_cell));
		column = 0;
		while (column < data->highest)
		{
			data->grid[row][column].value = 0;
			data->grid[row][column].is_fixed = false;
			column++;
		}
		row++;
	}
}
