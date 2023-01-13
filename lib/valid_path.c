#include "header.h"

void get_pos(t_window *asset, int *i, int *j)
{
	while(asset->copy[*j][*i] && asset->copy[*j][*i])
	{
		while(asset->copy[*j][*i] && asset->copy[*j][*i])
		{
			if(asset->copy[*j][*i] == 'P')
				return ;
			(*i)++;
		}
		(*i) = 0;
		(*j)++;
	}
}

void reco(t_window *asset, int x, int y)
{
	if(x >= (asset->i - 1) || (y >= asset->j) || x <= 0 || y <= 0)
		return ;
	if(asset->copy[y][x] == '1' || asset->copy[y][x] == 'N')
		return ;
	asset->copy[y][x] = 'N';
	reco(asset, x - 1, y);
	reco(asset, x + 1, y);
	reco(asset, x, y - 1);
	reco(asset, x, y + 1);
}

void check_exit(t_window *asset)
{
	int i = 0;
	int j = 0;
	while(asset->copy[i])
	{
		while(asset->copy[i][j])
		{
			if(asset->copy[i][j] == 'C' || asset->copy[i][j] == 'E')
				error();
			j++;
		}
		j = 0;
		i++;
	}
}
void valid_path(t_window *asset)
{
	int i = 0;
	int j = 0;
	get_pos(asset, &i, &j);
	reco(asset, i, j);
	i = 0;
	while(asset->copy[i])
	{
		printf("%s\n", asset->copy[i]);
		i++;
	}
	check_exit(asset);
}
