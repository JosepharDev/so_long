#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <mlx.h>
#include "get_next_line.h"

// # define w_win 800
// #  define h_win 800

// typedef struct s_player
// {
// 	int x;
// 	int y;
// }t_player;

typedef struct s_window
{
	char **map;
	char **copy;
	void *wall;
	void *avatar;
	void *enemy;
	void *ground;
	void *collectable;
	void *mlx_win;
	void *mlx;
	void *exit;
	int w_win;
	int h_win;
	int x;
	int y;
	int fd;
	int a;
	int b;
	int c_items;
	int p_items;
	int e_items;
}t_window;
int check_access(t_window *lng, int x, int y);
void move_player(t_window *mlx);
void fill_map(t_window *truct);
void init_asset(t_window *asset, char *av);
void check_map(int ac, char **av);
char *ft_strjoin(char *s1, char *s2);
char **ft_split(char *str, char c);
void fill(char **arr, t_window *lng);
#endif