#include "header.h"
char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int len = 0;
	char *str;
	if(!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	while(s2[i])
		i++;
	len = i;
	i = 0;
	while(s1[i])
		i++;
	len += i;
	str = malloc(sizeof(char) * len + 1);
	i = 0;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	len = 0;
	while(s2[len])
	{
		str[i] = s2[len];
		len++;
		i++;
	}
	str[i] = '\0';
	return (str);
}