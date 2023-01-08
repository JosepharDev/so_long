#include "header.h"
void ft_error(void)
{
	write(1, "invalid arg\n", 12);
	exit(0);
}
void check_map(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		if(strlen(av[1]) > 4)
		{
			i = strlen(av[1]);
			if(strncmp(&av[1][i - 4], ".ber", 4) != 0)
				ft_error();
		}
		else
			ft_error();
	}
	else
		ft_error();
}