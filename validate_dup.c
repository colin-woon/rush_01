/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:19:34 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 14:20:15 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

bool	is_duplicate(t_data *data, int to_check, int row, int col);
bool	is_duplicate_row(t_data *data, int to_check, const int fix, int i_cur);
bool	is_duplicate_col(t_data *data, int to_check, const int fix, int i_cur);

bool	is_duplicate_col(t_data *data, int to_check, const int fix, int i_cur)
{
	int	i;

	i = -1;
	while(++i <= data->end)
	{
		if (i == i_cur)
			continue;
		if (to_check == data->grid[i][fix].value)
			return (true);
	}
	return (false);
}

bool	is_duplicate_row(t_data *data, int to_check, const int fix, int i_cur)
{
	int	i;

	i = -1;
	while(++i <= data->end)
	{
		if (i == i_cur)
			continue;
		if (to_check == data->grid[fix][i].value)
			return (true);
	}
	return (false);
}

bool	is_duplicate(t_data *data, int to_check, int row, int col)
{
	if (is_duplicate_col(data, to_check, col, row) \
	|| is_duplicate_row(data, to_check, row, col))
		return (true);
	return (false);
}
