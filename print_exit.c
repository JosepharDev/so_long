/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:28:45 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/18 11:21:40 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_exit(int error)
{
	write(2, "Error\n", 6);
	if (error == 1)
		write(2, "error xpm to file", 17);
	else if (error == 2)
		write(2, "map Allocation", 14);
	else if (error == 3)
		write(2, "error in new window", 19);
	else if (error == 4)
		write(2, "error can't read from file", 26);
	else if (error == 5)
		write(2, "get_next_line return NULL", 25);
	else if (error == 6)
		write(2, "error in split arg", 18);
	exit(1);
}
