#include "header.h"

void init_asset(t_window *asset, char *av)
{
	asset->mlx = mlx_init();
	asset->avatar = mlx_xpm_file_to_image(asset->mlx, "../image/p.xpm",&asset->x ,&asset->y);
	asset->wall = mlx_xpm_file_to_image(asset->mlx, "../image/w.xpm", &asset->x, &asset->y);
	asset->ground = mlx_xpm_file_to_image(asset->mlx, "../image/g.xpm", &asset->x, &asset->y);
	asset->exit = mlx_xpm_file_to_image(asset->mlx, "../image/e.xpm", &asset->x, &asset->y);
	asset->collectable = mlx_xpm_file_to_image(asset->mlx, "../image/c.xpm", &asset->x, &asset->y);
	asset->fd = open(av, O_RDONLY);
  	if(asset->fd == -1)
   	 printf("open -1\n");
	asset->x = 0;
	asset->y = 0;
	asset->c_items = 0;
	asset->p_items = 0;
	asset->e_items = 0;
	char *arr = 0;
	char *map = 0;
	asset->map = NULL;
	int j = 0;
	arr = get_next_line(asset->fd);
	int i = strlen(arr);
	while(arr)
	{
		map = ft_strjoin(map, arr);
    	arr = get_next_line(asset->fd);
		j++;
	}
	i--;
	asset->map = ft_split(map, '\n');
	asset->copy = ft_split(map, '\n');
	asset->w_win = i * 40;
	asset->h_win = j * 40;
	close(asset->fd);
	if(i <= j)
	{
		printf("not valid rectangel");
		exit(1);
	}

	asset->mlx_win = mlx_new_window(asset->mlx, asset->w_win, asset->h_win, "Hello world!");
}