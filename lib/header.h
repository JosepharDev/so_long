/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:49:16 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/11 15:52:36 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_window
{
	char	**map;
	char	**copy;
	void	*wall;
	void	*up;
	void	*left;
	void	*down;
	void	*right;
	void	*ground;
	void	*collectable;
	void	*mlx_win;
	void	*mlx;
	void	*exit;
	int		w_win;
	int		h_win;
	int		x;
	int		y;
	int		fd;
	int		px;
	int		py;
	int		c_items;
	int		p_items;
	int		e_items;
	int		mv;
	int		i;
	int		j;
}t_window;

int		check_access(t_window *lng, int x, int y);
void	move_player(t_window *mlx, void *pos, int flag);
void	fill_map(t_window *truct);
void	init_asset(t_window *asset, char *av);
void	check_map(int ac, char **av);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);
void	fill(char **arr, t_window *lng);
void	check_items(char *str);
void	check_walls(t_window *data);
void	error(void);
int		handle_input(int key, t_window *data);
void	print(int n);
int		ft_strlen(char *str);
void	valid_path(t_window *asset);

#endif