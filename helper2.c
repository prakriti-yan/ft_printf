/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:48:10 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 14:59:46 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

int					sp_atoi(char **s)
{
	int nb;

	nb = 0;
	while (**s && (**s <= '9' && **s >= '0'))
	{
		nb = nb * 10 + **s - 48;
		(*s)++;
	}
	(*s)--;
	return (nb);
}

int					length(unsigned long long nb)
{
	int len;

	len = 1;
	while ((nb /= 10) > 0)
		len++;
	return (len);
}

unsigned long long	power(int preci)
{
	unsigned long long res;

	res = 1;
	while (preci > 0)
	{
		res = 10 * res;
		preci--;
	}
	return (res);
}

void				reset_p(t_struct *p)
{
	ft_strclr(p->flag);
	p->width = 0;
	p->precision = -1;
	ft_strclr(p->length);
}

int					put_percentage(t_struct *p, int nb)
{
	if (ft_strchr(p->flag, '-') != NULL)
	{
		ft_putchar('%');
		print_padding(p->width, 1, ' ');
	}
	if (ft_strchr(p->flag, '-') == NULL)
	{
		print_padding(p->width, 1, ' ');
		ft_putchar('%');
	}
	nb += p->width ? p->width : 1;
	return (nb);
}
