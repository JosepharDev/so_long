/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:24 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/11 15:52:58 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(void)
{
	printf("invalid map");
	exit(1);
}

void	check_items(char *str)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			p++;
		if (str[i] == 'C')
			c++;
		if (str[i] == 'E')
			e++;
		if (str[i] != 'P' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != '1' && str[i] != '0' && str[i] != '\n')
			error();
		i++;
	}
	if (p != 1 || e != 1 || c == 0)
		error();
}

void	check_walls(t_window *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			error();
		i++;
	}
	i = 0;
	while (data->map[data->j - 1][i])
	{
		if (data->map[data->j - 1][i] != '1')
			error();
		i++;
	}
}
