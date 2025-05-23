/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:03 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 20:03:30 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_solution {
	int		value;
	bool	is_fixed;
}	t_solution;

typedef struct s_validation {
	int	can_see;
	int	i;
	int	j;
} t_validation;

typedef struct s_data {
	t_solution	**grid;
	int			highest;
	int			end;
	int			*col_up;
	int			*col_down;
	int			*row_left;
	int			*row_right;
}	t_data;

int		ft_atoi(char number);
void	ft_putstr(char *str);
char	ft_itoa(int digit);

void	parse_array(int **array, int highest, char **av, int start);
void	parse(t_data *data, char **av);
void	init_grid(t_data *data);
int		get_highest(char **av);

void	fill_corners(t_data *data);

void	fill_edges(t_data *data);
