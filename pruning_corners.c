/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruning_corners.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:41:51 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 19:23:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	fill_corners(t_data *data);

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
