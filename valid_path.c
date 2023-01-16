/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:44:35 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/14 22:37:58 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_pos(t_window *asset, int *i, int *j, char c)
{
	while (asset->copy[*j])
	{
		while (asset->copy[*j][*i])
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
	while (asset->copy[j])
	{
		while (asset->copy[j][i])
		{
			if (asset->copy[j][i] == 'C')
				error();
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_exit_find(t_window *str, int i, int j)
{
	if (str->copy[j][i] == 'E')
	{
		if (str->map[j][i + 1] != '1' || str->copy[j][i - 1] != '1' ||
			str->copy[j - 1][i] != '1' || str->copy[j + 1][i] != '1')
			return ;
		else
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
	ft_exit_find(asset, i, j);
}
