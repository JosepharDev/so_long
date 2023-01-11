/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:54 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/11 15:52:26 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	write(2, "invalid arg\n", 12);
	exit(1);
}

char **test(char *av)
{
	char **copy = ft_split(av, '/');
	int i = 0;
	while(copy[i])
		i++;
	return (copy);
}

void	check_map(int ac, char **av)
{
	int	i;

	i = 0;
	int j = 0;
	char **str = test(av[1]);
	while(str[i])
		i++;
	if (ac == 2)
	{
		if (strlen(str[i - 1]) > 4)
		{
			j = strlen(str[i - 1]);
			if (strncmp(&str[i - 1][j - 4], ".ber", 4) != 0)
				ft_error();
		}
		else
			ft_error();
	}
	else
		ft_error();
}