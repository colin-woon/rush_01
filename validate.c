/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:48 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 14:26:18 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

bool	is_valid_col(t_data *data, const int i_clue);
bool	is_valid_row(t_data *data, const int i_clue);

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
