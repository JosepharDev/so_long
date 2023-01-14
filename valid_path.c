/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:44:35 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/14 13:09:25 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_pos(t_window *asset, int *i, int *j, char c)
{
	while (asset->copy[*j][*i] && asset->copy[*j][*i])
	{
		while (asset->copy[*j][*i] && asset->copy[*j][*i])
		{
			if (asset->copy[*j][*i] == c)
				return ;
			(*i)++;
		}
		(*i) = 0;
		(*j)++;
	}
}

void	reco(t_window *asset, int x, int y)
{
	if (x >= (asset->i - 1) || (y >= asset->j) || x <= 0 || y <= 0)
		return ;
	if (asset->copy[y][x] == '1' || asset->copy[y][x] == 'E' ||
		asset->copy[y][x] == 'N')
		return ;
	asset->copy[y][x] = 'N';
	reco(asset, x - 1, y);
	reco(asset, x + 1, y);
	reco(asset, x, y - 1);
	reco(asset, x, y + 1);
}

void	check_exit(t_window *asset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (asset->copy[i])
	{
		while (asset->copy[i][j])
		{
			if (asset->copy[i][j] == 'C')
				error();
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_exit_find(char **str, int i, int j)
{
	if (str[i][j] == 'E')
	{
		if (str[i][j + 1] == '1' && str[i][j - 1] == '1' &&
			str[i - 1][j] == '1' && str[i + 1][j] == '1')
			error();
	}
}

void	valid_path(t_window *asset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	get_pos(asset, &i, &j, 'P');
	reco(asset, i, j);
	check_exit(asset);
	i = 0;
	j = 0;
	get_pos(asset, &i, &j, 'E');
	ft_exit_find(asset->copy, i, j);
}
