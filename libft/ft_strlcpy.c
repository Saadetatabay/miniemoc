/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:19:06 by satabay           #+#    #+#             */
/*   Updated: 2025/06/24 13:07:34 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (*(src + i))
		i++;
	if (size == 0)
		return (i);
	while (*src != '\0' && n < size - 1)
	{
		*dst++ = *src++;
		n++;
	}
	*dst = '\0';
	return (i);
}
