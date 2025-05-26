/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:48 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 16:36:54 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

bool	is_valid_col(t_data *data, const int i_clue);
bool	is_valid_row(t_data *data, const int i_clue);
bool	is_valid_then_move(t_data *data);

bool	is_valid_row(t_data *data, const int i_clue)
{
	if (is_valid_from_left(data, data->row_left[i_clue], i_clue) \
&& is_valid_from_right(data, data->row_right[i_clue], i_clue))
		return (true);
	return (false);
}

bool	is_valid_col(t_data *data, const int i_clue)
{
	if (is_valid_from_top(data, data->col_up[i_clue], i_clue) \
&& is_valid_from_bottom(data, data->col_down[i_clue], i_clue))
		return (true);
	return (false);
}

bool	is_valid_then_move(t_data *data)
{
	bool	is_valid;

	is_valid = true;
	if (data->col == data->end)
	{
		if (!is_valid_row(data, data->row))
			is_valid = false;
	}
	if (data->row == data->end)
	{
		if (!is_valid_col(data, data->col))
			is_valid = false;
	}
	if (is_valid)
		increment_grid_index(data, &data->row, &data->col);
	return (is_valid);
}
