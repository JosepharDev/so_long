/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:54 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/13 17:26:46 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	write(2, "invalid arg\n", 12);
	exit(1);
}

void	test(char *av, t_window *lng)
{
	if(av[0] == '\0')
		exit(1);
	lng->str = ft_split(av, '/');
	if(!lng->str)
		exit(1);
}

void	check_map(int ac, char **av, t_window *lng)
{
	int	i;

	i = 0;
	int j = 0;
	test(av[1], lng);
		if(!lng->str)
			exit(1);
	while(lng->str[i])
		i++;
	if (ac == 2)
	{
		if (strlen(lng->str[i - 1]) > 4)
		{
			j = strlen(lng->str[i - 1]);
			if (strncmp(&lng->str[i - 1][j - 4], ".ber", 4) != 0)
				ft_error();
		}
		else
			ft_error();
	}
	else
		ft_error();
}