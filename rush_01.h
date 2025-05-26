/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:03 by cwoon             #+#    #+#             */
/*   Updated: 2025/05/26 15:41:55 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum {
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
} e_from;

typedef struct s_cell {
	int		value;
	bool	is_fixed;
}	t_cell;

typedef struct s_validation {
	int	can_see;
	int	i;
	int	cur_max;
} t_validation;

typedef struct s_data {
	t_cell	**grid;
	int			highest;
	int			end;
	int			to_check;
	int			row;
	int			col;
	int			*col_up;
	int			*col_down;
	int			*row_left;
	int			*row_right;
}	t_data;

int		ft_atoi(char number);
void	ft_putstr(char *str);
char	ft_itoa(int digit);

void	print_grid(t_data *data);
void	decrement_grid_index(t_data *data, int *row, int* col);
void	increment_grid_index(t_data *data, int *row, int* col);

void	parse_array(int **array, int highest, char **av, int start);
void	parse(t_data *data, char **av);
void	init_grid(t_data *data);
int		get_highest(char **av);

void	fill_corners(t_data *data);
void	fill_edges(t_data *data);

void	init_validation_vars(t_validation *var, t_data *data, e_from dir, int fix);

bool	is_duplicate(t_data *data, int to_check, int row, int col);
bool	is_duplicate_row(t_data *data, int to_check, const int fix, int i_cur);
bool	is_duplicate_col(t_data *data, int to_check, const int fix, int i_cur);

bool	is_valid_from_right(t_data *data, const int clue, const int fix);
bool	is_valid_from_left(t_data *data, const int clue, const int fix);
bool	is_valid_from_bottom(t_data *data, const int clue, const int fix);
bool	is_valid_from_top(t_data *data, const int clue, const int fix);

bool	is_valid_col(t_data *data, const int i_clue);
bool	is_valid_row(t_data *data, const int i_clue);
bool	is_valid_then_move(t_data *data);
