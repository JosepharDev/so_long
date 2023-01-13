/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:04:02 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/13 18:03:20 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*read_map(t_window *data, char *av)
{
	char	*line;
	char	*submap;

	submap = NULL;
	line = NULL;
	data->i = 0;
	data->j = 0;
	data->fd = open(av, O_RDONLY);
	if (data->fd == -1)
		exit(1);
	line = get_next_line(data->fd);
	if(!line)
		error();
	data->i = ft_strlen(line);
	while (line)
	{
		if (line[0] != '1' || line[data->i - 2] != '1' || line[0] == '\n')
			error();
		printf("%s", line);
		submap = ft_strjoin(submap, line);
		free(line);
		line = get_next_line(data->fd);
		if (line && ft_strlen(line) != data->i)
			error();
		data->j++;
	}
	data->i--;
	free(line);
	close(data->fd);
	return (submap);
}

void	init_image(t_window *asset)
{
	asset->mlx = mlx_init();
	asset->up = mlx_xpm_file_to_image(asset->mlx,
			"../image/up.xpm", &asset->x, &asset->y);
	asset->down = mlx_xpm_file_to_image(asset->mlx,
			"../image/down.xpm", &asset->x, &asset->y);
	asset->left = mlx_xpm_file_to_image(asset->mlx,
			"../image/left.xpm", &asset->x, &asset->y);
	asset->right = mlx_xpm_file_to_image(asset->mlx,
			"../image/right.xpm", &asset->x, &asset->y);
	asset->wall = mlx_xpm_file_to_image(asset->mlx,
			"../image/w.xpm", &asset->x, &asset->y);
	asset->ground = mlx_xpm_file_to_image(asset->mlx,
			"../image/g.xpm", &asset->x, &asset->y);
	asset->exit = mlx_xpm_file_to_image(asset->mlx,
			"../image/e.xpm", &asset->x, &asset->y);
	asset->collectable = mlx_xpm_file_to_image(asset->mlx,
			"../image/c.xpm", &asset->x, &asset->y);
}

void	init_asset(t_window *asset, char *av)
{
	char	*map;

	map = read_map(asset, av);
	asset->map = ft_split(map, '\n');
	asset->copy = ft_split(map, '\n');
	check_items(map);
	free(map);
	check_walls(asset);
	init_image(asset);
	asset->x = 0;
	asset->y = 0;
	asset->c_items = 0;
	asset->p_items = 0;
	asset->e_items = 0;
	asset->mv = 1;
	asset->w_win = asset->i * 40;
	asset->h_win = asset->j * 40;
	if(asset->w_win >= 2720 || asset->h_win >= 1400)
	{
		printf("fadfbf\n");
		exit(1);
	}
	// while(1);
	if (asset->i <= asset->j)
		error();
	asset->mlx_win = mlx_new_window(asset->mlx,
			asset->w_win, asset->h_win, "so_long");
}
