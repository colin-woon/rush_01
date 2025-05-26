/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:18:33 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 16:35:13 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	init_validation_vars(t_validation *var, t_data *data,\
	t_from dir, int fix);

void	init_validation_vars(t_validation *var, t_data *data,\
	t_from dir, int fix)
{
	var->can_see = 1;
	if (dir == TOP)
	{
		var->cur_max = data->grid[0][fix].value;
		var->i = 0;
	}
	else if (dir == BOTTOM)
	{
		var->cur_max = data->grid[data->end][fix].value;
		var->i = data->end;
	}
	else if (dir == LEFT)
	{
		var->i = 0;
		var->cur_max = data->grid[fix][0].value;
	}
	else if (dir == RIGHT)
	{
		var->i = data->end;
		var->cur_max = data->grid[fix][data->end].value;
	}
}
