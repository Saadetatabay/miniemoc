/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:02:02 by satabay           #+#    #+#             */
/*   Updated: 2025/06/25 10:39:12 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	concatenate(char *cat, const char *s, int *j)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		*(cat + *j) = *(s + i);
		i++;
		(*j)++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		len;
	int		j;

	j = 0;
	len = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * (len + 1));
	if (!cat)
		return (0);
	concatenate(cat, s1, &j);
	concatenate(cat, s2, &j);
	*(cat + j) = '\0';
	return (cat);
}
