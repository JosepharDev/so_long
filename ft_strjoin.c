/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:17:01 by yoyahya           #+#    #+#             */
/*   Updated: 2023/01/09 18:26:36 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	size_t			tlen;
	size_t			i;
	size_t			j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	tlen = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(tlen * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
