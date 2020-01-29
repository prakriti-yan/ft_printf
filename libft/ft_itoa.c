/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:37:51 by yyan              #+#    #+#             */
/*   Updated: 2019/10/24 14:53:46 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_getsize(int nb)
{
	unsigned int size;
	unsigned int n;

	size = 0;
	if (nb < 0)
	{
		n = (unsigned int)(nb * -1);
		size = size + 1;
	}
	else
		n = (unsigned int)nb;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size + 1);
}

char				*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	unsigned int	index;
	unsigned int	size;

	size = ft_getsize(n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		str[0] = '-';
	}
	else
		nb = (unsigned int)n;
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + 48);
		nb = nb / 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
