#include <stdlib.h>
#include <stdio.h>
int wcount(char c, char *str)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if(str[i] == c)
			i++;
		else
		{
			count++;
			while(str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}
char *mword(char c, char *str, int *i)
{
	int k = 0;
	int j = 0;
	char *copy;
	while(str[*i] && str[*i] == c)
		(*i)++;
	k = *i;
	while(str[*i] && str[*i] != c)
	{
		(*i)++;
		j++;
	}
	copy = malloc(sizeof(char) * j + 1);
	j = 0;
	while(str[k] && str[k] != c)
	{
		copy[j] = str[k];
		k++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
char **free_arr(char **arr)
{
	int i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
char **ft_split(char *str, char c)
{
	int i = 0;
	int count = 0;
	int j = 0;
	char **arr;
	count = wcount(c, str);
	arr = malloc(sizeof(char *) * count + 1);
	while(i < count)
	{
		arr[i] = mword(c, str, &j);
		if(!arr[i])
			return (free_arr(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}

// int main()
// {
// 	int i = 0;
// 	char str[] = "1111111111\n1E00000001\n1000111101\n1000P00111\n1011111011\n1000000001\n1110C00111\n1111011111\n1000000001\n1111111111";
// 	char **arr;
// 	arr = ft_split(str, ' ');
// 	while(arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// }