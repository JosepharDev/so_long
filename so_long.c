/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:34:00 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/17 19:18:04 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 10)
	{
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	print(int n)
{
	write(1, "movment number ", 15);
	ft_putnbr(n);
	write(1, "\n", 1);
}

void	move_player(t_window *mlx, void *pos, int flag)
{
	if (flag == 1)
	{
		mlx->px = mlx->x;
		mlx->py = mlx->y;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		pos, mlx->px, mlx->py);
}

int	ft_close(t_window *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_window	truct;

	if (ac == 2)
	{
		check_map(ac, av, &truct);
		init_asset(&truct, av[1]);
		fill(truct.map, &truct);
		mlx_hook(truct.mlx_win, 2, 0, handle_input, &truct);
		mlx_hook(truct.mlx_win, 17, 0, ft_close, &truct);
		mlx_loop(truct.mlx);
	}
	else
	{
		write(2, "Error\n", 6);
		write(2, "Number of arg not valid", 23);
		exit(1);
	}
}
