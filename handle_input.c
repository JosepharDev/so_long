/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:45:53 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/14 20:59:36 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	help_handl(int key, t_window *data)
{
	if (key == 125 && check_access(data, data->px / 40,
			data->py / 40 + 1) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->ground, data->px, data->py);
		data->map[data->py / 40][data->px / 40] = '0';
		data->py += 40;
		move_player(data, data->down, 0);
		print(data->mv++);
	}
	else if (key == 123 && check_access(data, data->px / 40 - 1,
			data->py / 40) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			data->px, data->py);
		data->map[data->py / 40][data->px / 40] = '0';
		data->px -= 40;
		move_player(data, data->left, 0);
		print(data->mv++);
	}
	else if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
}

int	handle_input(int key, t_window *data)
{
	help_handl(key, data);
	if (key == 126 && check_access(data, data->px / 40, data->py / 40 - 1) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->ground, data->px, data->py);
		data->map[data->py / 40][data->px / 40] = '0';
		data->py -= 40;
		move_player(data, data->up, 0);
		print(data->mv++);
	}
	else if (key == 124 && check_access(data, data->px / 40 + 1,
			data->py / 40) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->ground, data->px, data->py);
		data->map[data->py / 40][data->px / 40] = '0';
		data->px += 40;
		move_player(data, data->right, 0);
		print(data->mv++);
	}
	return (0);
}
