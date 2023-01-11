/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:09:19 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/10 16:04:26 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_access(t_window *lng, int x, int y)
{
	if (lng->map[y][x] == '1')
		return (0);
	if (lng->map[y][x] == 'E' && lng->c_items == 0)
	{
		printf("YOU WIN");
		print(lng->mv++);
		exit(0);
	}
	if (lng->map[y][x] == 'E')
		return (0);
	if (lng->map[y][x] == 'C')
		lng->c_items--;
	lng->map[y][x] = 'P';
	return (1);
}

int	help(char c, t_window *lng)
{
	if (c == '1')
		mlx_put_image_to_window(lng->mlx, lng->mlx_win,
			lng->wall, lng->x, lng->y);
	else if (c == '0')
		mlx_put_image_to_window(lng->mlx, lng->mlx_win,
			lng->ground, lng->x, lng->y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(lng->mlx, lng->mlx_win,
			lng->collectable, lng->x, lng->y);
		lng->c_items++;
	}
	else if (c == 'E')
		mlx_put_image_to_window(lng->mlx, lng->mlx_win,
			lng->exit, lng->x, lng->y);
	else
		return (1);
	return (0);
}

void	fill(char **arr, t_window *lng)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (help(arr[i][j], lng) == 1)
			{
				if (arr[i][j] == 'P')
					move_player(lng, lng->up, 1);
				else
					error();
			}
			lng->x += 40;
			j++;
		}
		lng->x = 0;
		j = 0;
		i += 1;
		lng->y += 40;
	}
}
