/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_toa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:49:29 by epalomak          #+#    #+#             */
/*   Updated: 2021/12/14 14:39:31 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int	ft_unb_count(uintmax_t nb)
{
	long	c;

	c = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

char	*ft_uintmax_itoa(uintmax_t n)
{
	uintmax_t	i;
	char		*dst;

	i = ft_unb_count(n);
	dst = ft_strnew(i + 1);
	if (!dst)
		return (NULL);
	else
		i--;
	if (n == 0)
		dst[0] = '0';
	while (n > 0)
	{
		dst[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}
