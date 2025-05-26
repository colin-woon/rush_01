/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruning_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:39:44 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 16:26:04 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void		fill_edges(t_data *data);
static void	fill_top(t_data *data);
static void	fill_left(t_data *data);
static void	fill_right(t_data *data);
static void	fill_bottom(t_data *data);

void	fill_edges(t_data *data)
{
	fill_top(data);
	fill_left(data);
	fill_right(data);
	fill_bottom(data);
}

static void	fill_top(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->end)
	{
		if (data->col_up[i] == 1)
		{
			data->grid[0][i].value = data->highest;
			data->grid[0][i].is_fixed = true;
		}
		i++;
	}
}

static void	fill_bottom(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->end)
	{
		if (data->col_down[i] == 1)
		{
			data->grid[data->end][i].value = data->highest;
			data->grid[data->end][i].is_fixed = true;
		}
		i++;
	}
}

static void	fill_left(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->end)
	{
		if (data->row_left[i] == 1)
		{
			data->grid[i][0].value = data->highest;
			data->grid[i][0].is_fixed = true;
		}
		i++;
	}
}

static void	fill_right(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->end)
	{
		if (data->row_right[i] == 1)
		{
			data->grid[i][data->end].value = data->highest;
			data->grid[i][data->end].is_fixed = true;
		}
		i++;
	}
}
