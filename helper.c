/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:30:00 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 16:06:02 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void			strrev(char *s)
{
	int		len;
	int		i;
	char	tp;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (len >= i)
	{
		tp = s[i];
		s[i] = s[len];
		s[len] = tp;
		i++;
		len--;
	}
}

char			*convert(char *s, unsigned long long nb, int base)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		s[i] = ((nb % base) <= 9) ? ((nb % base) + '0') : \
		((nb % base) + 'a' - 10);
		nb /= base;
		i++;
	}
	s[i] = '\0';
	strrev(s);
	return (s);
}

void			print_padding(int n, int n2, char c)
{
	while (n > n2)
	{
		ft_putchar(c);
		n--;
	}
}

int				ft_get_nb2(int n1, int n2, int n3)
{
	if (n1 || n2 != -1)
	{
		if (n2 <= n3)
		{
			if (n2 > n1)
				return (n2);
			return (n1);
		}
		else
		{
			if (n3 > n1)
				return (n3);
			return (n1);
		}
	}
	return (n3);
}

int				ft_get_nb(int n1, int n2, int n3)
{
	if (n1 >= n2 && n1 >= n3)
		return (n1);
	else if (n2 >= n1 && n2 >= n3)
		return (n2);
	else
		return (n3);
}
