/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:54 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/14 11:23:17 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	write(2, "invalid arg\n", 12);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	test(char *av, t_window *lng)
{
	if (av[0] == '\0')
		ft_error();
	lng->str = ft_split(av, '/');
	if (!lng->str)
		print_exit(6);
}

void	check_map(int ac, char **av, t_window *lng)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	test(av[1], lng);
	if (!lng->str)
		exit(1);
	while (lng->str[i])
		i++;
	if (ac == 2)
	{
		if (ft_strlen(lng->str[i - 1]) > 4)
		{
			j = ft_strlen(lng->str[i - 1]);
			if (ft_strncmp(&lng->str[i - 1][j - 4], ".ber", 4) != 0)
				ft_error();
		}
		else
			ft_error();
	}
	else
		ft_error();
}
