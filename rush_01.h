/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:03 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/23 17:48:25 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_solution {
	int		value;
	bool	is_fixed;
}	t_solution;

typedef struct s_data {
	t_solution	**grid;
	int			edge_length;
	int			*col_up;
	int			*col_down;
	int			*row_left;
	int			*row_right;
}	t_data;

int		ft_atoi(char number);
void	ft_putstr(char *str);

void	parse_array(int **array, int edge_length, char **av, int start);
void	parse(t_data *data, char **av);
void	init_grid(t_data *data);
int		get_edge_length(char **av);
