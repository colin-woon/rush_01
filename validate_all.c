/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:21:14 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 14:22:00 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

bool	is_valid_from_right(t_data *data, const int clue, const int fix);
bool	is_valid_from_left(t_data *data, const int clue, const int fix);
bool	is_valid_from_bottom(t_data *data, const int clue, const int fix);
bool	is_valid_from_top(t_data *data, const int clue, const int fix);

bool is_valid_from_top(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, TOP, fix);
	while (var.i <= data->end)
	{
		if (data->grid[var.i][fix].value == data->highest)
		{
			if (var.i != 0)
				var.can_see++;
			break ;

		}
		if (var.cur_max < data->grid[var.i][fix].value)
		{
			var.cur_max =  data->grid[var.i][fix].value;
			var.can_see++;
		}
		var.i++;
	}
	if (clue == var.can_see)
		return (true);
	return (false);
}

bool is_valid_from_bottom(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, BOTTOM, fix);
	while (var.i >= 0)
	{
		if (data->grid[var.i][fix].value == data->highest)
		{
			if (var.i != data->end)
				var.can_see++;
			break ;

		}
		if (var.cur_max < data->grid[var.i][fix].value)
		{
			var.cur_max =  data->grid[var.i][fix].value;
			var.can_see++;
		}
		var.i--;
	}
	if (clue == var.can_see)
		return (true);
	return (false);
}

bool is_valid_from_left(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, LEFT, fix);
	while (var.i <= data->end)
	{
		if (data->grid[fix][var.i].value == data->highest)
		{
			if (var.i != 0)
				var.can_see++;
			break ;
		}
		if (var.cur_max < data->grid[fix][var.i].value)
		{
			var.cur_max =  data->grid[fix][var.i].value;
			var.can_see++;
		}
		var.i++;
	}
	if (clue == var.can_see)
		return (true);
	return (false);
}

bool is_valid_from_right(t_data *data, const int clue, const int fix)
{
	t_validation var;

	init_validation_vars(&var, data, RIGHT, fix);
	while (var.i >= 0)
	{
		if (data->grid[fix][var.i].value == data->highest)
		{
			if (var.i != data->end)
				var.can_see++;
			break ;
		}
		if (var.cur_max < data->grid[fix][var.i].value)
		{
			var.cur_max =  data->grid[fix][var.i].value;
			var.can_see++;
		}
		var.i--;
	}
	if (clue == var.can_see)
		return (true);
	return (false);
}
