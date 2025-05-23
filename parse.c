/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:46:31 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 17:47:44 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	parse_array(int **array, int edge_length, char **av, int start);
void	parse(t_data *data, char **av);
void	init_grid(t_data *data);
int		get_edge_length(char **av);

void	parse(t_data *data, char **av)
{
	data->edge_length = get_edge_length(av);
	printf("%d\n", data->edge_length);
	data->grid = malloc(data->edge_length * sizeof(t_solution *));
	init_grid(data);
	parse_array(&data->col_up, data->edge_length, av, 0);
	parse_array(&data->col_down, data->edge_length, av, data->edge_length);
	parse_array(&data->row_left, data->edge_length, av, 2 * data->edge_length);
	parse_array(&data->row_right, data->edge_length, av, 3 * data->edge_length);
}

int	get_edge_length(char **av)
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

void	parse_array(int **array, int edge_length, char **av, int start)
{
	int	i;
	int	number;
	int	array_len;

	i = 0;
	number = 0;
	array_len = 0;
	*array = malloc((edge_length + 1) * sizeof(int));
	while (array_len < edge_length)
	{
		if (av[1][i] == ' ')
		{
			i++;
			continue;
		}
		if (number >= start)
		{
			(*array)[array_len] = ft_atoi(av[1][i]);
			printf("%d ", (*array)[array_len]);
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
	while (row < data->edge_length)
	{
		data->grid[row] = malloc(data->edge_length * sizeof(t_solution));
		column = 0;
		while (column < data->edge_length)
		{
			data->grid[row][column].value = 0;
			data->grid[row][column].is_fixed = false;
			// printf("%d ", data->grid[row][column].value);
			column++;
		}
		row++;
	}
}
