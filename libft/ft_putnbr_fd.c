/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:16:04 by satabay           #+#    #+#             */
/*   Updated: 2025/06/24 13:07:07 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	a;
	char		c;

	a = (long int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		a = a * -1;
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		c = (a % 10) + '0';
		write(fd, &c, 1);
	}
	if (a < 10)
	{
		c = (a + '0');
		write(fd, &c, 1);
	}
}
