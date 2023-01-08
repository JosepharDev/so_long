#include "header.h"

int check_access(t_window *lng, int x, int y)
{
	if(lng->map[y][x] == '1')
		return (0);
	if(lng->map[y][x] == 'E' && lng->c_items == 0)
		exit(0);
	if(lng->map[y][x] == 'E')
		return (0);
	if(lng->map[y][x] == 'C')
		lng->c_items--;
	lng->map[y][x] = 'P';

	return (1);
}
void fill(char **arr, t_window *lng)
{
  int i = 0;
  int j = 0;
  while(arr[i])
  {
		while(arr[i][j])
		{
				if(arr[i][j] == '1')
				{
					mlx_put_image_to_window(lng->mlx, lng->mlx_win, lng->wall, lng->x, lng->y);
				}
				else if(arr[i][j] == '0')
				{
					mlx_put_image_to_window(lng->mlx, lng->mlx_win, lng->ground, lng->x, lng->y);
				}
				else if(arr[i][j] == 'C')
				{
					mlx_put_image_to_window(lng->mlx, lng->mlx_win, lng->ground, lng->x, lng->y);
					mlx_put_image_to_window(lng->mlx, lng->mlx_win, lng->collectable, lng->x, lng->y);
					lng->c_items++;
				}
				else if(arr[i][j] == 'E')
				{
					mlx_put_image_to_window(lng->mlx, lng->mlx_win, lng->ground, lng->x, lng->y);
					mlx_put_image_to_window(lng->mlx, lng->mlx_win, lng->exit, lng->x, lng->y);
				}
				else if(arr[i][j] == 'P')
				{
					lng->a = lng->x;
					lng->b = lng->y;
					move_player(lng);
				}
				else if(arr[i][j] != 'P' && arr[i][j] != '0' && arr[i][i] != 'C' && arr[i][j] != 'E')
				{
					printf("Invalid character in map");
					exit(1);
				}
			lng->x+=40;
			j++;
		}
		lng->x = 0;
		j = 0;
		i += 1; 
		lng->y += 40;
	}
}