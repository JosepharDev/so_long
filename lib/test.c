#include "header.h"

void move_player(t_window *mlx)
{

	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->avatar, mlx->a, mlx->b);
}

int	handle_input(int key, t_window *data)
{
	data->map[data->b/40 ][data->a/40 ] = '0';
	if(key == 126 && check_access(data, data->a/40, data->b/40 - 1) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, data->a, data->b);
		data->b -= 40;
		move_player(data);
	}
	else if(key == 124 && check_access(data, data->a/40 + 1, data->b/40) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, data->a, data->b);
		data->a += 40;
		move_player(data);
	}
	else if(key == 125 && check_access(data, data->a/40, data->b/40 + 1) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, data->a, data->b);
		data->b += 40;
		move_player(data);
	}
	else if(key == 123 && check_access(data, data->a/40 - 1, data->b/40) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, data->a, data->b);
		data->a -= 40;
		move_player(data);
	}
	else if(key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	int j = 0;
	printf("map\n");
	while(data->map[j])
	{
		printf("%s\n", data->map[j]);
		j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_window truct;
	check_map(ac, av);
	init_asset(&truct, av[1]);
	// is_valid(truct);
	fill(truct.map, &truct);
	mlx_hook(truct.mlx_win,2 , 0, &handle_input, &truct);
	mlx_loop(truct.mlx);
}