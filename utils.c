/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:20 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 15:53:51 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int		ft_atoi(char number);
void	ft_putstr(char *str);
char	ft_itoa(int digit);
void	clear_memory(t_data *data);

int	ft_atoi(char number)
{
	if (number >= '1' && number <= '9')
		return(number - '0');
	return (0);
}

char	ft_itoa(int digit)
{
	return((char)(digit + '0'));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}

void	clear_memory(t_data *data)
{
	int	i;

	i = 0;
	if (data->grid)
	{
		while (i <= data->end)
		{
			free(data->grid[i]);
			i++;
		}
		free(data->grid);
	}
	if (data->col_up)
		free(data->col_up);
	if (data->col_down)
		free(data->col_down);
	if (data->row_left)
		free(data->row_left);
	if (data->row_right)
		free(data->row_right);
}
