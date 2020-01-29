/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:21:58 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 17:10:05 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

void		ft_putnstr(char *s, int n)
{
	int i;

	i = 0;
	if (n != -1)
	{
		while (i < n && s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	else
		ft_putstr(s);
}

int			put_zero(t_struct *p, int nb)
{
	if (ft_strchr(p->flag, '-') != NULL)
	{
		if (p->precision > 1)
			print_padding(p->precision, 1, '0');
		ft_putchar((p->precision == 0) ? ' ' : '0');
		print_padding((p->width), (p->precision > 1) ? (p->precision) : 1, ' ');
	}
	else if (ft_strchr(p->flag, '-') == NULL)
	{
		if (p->precision > 1)
		{
			print_padding(p->width, p->precision, ' ');
			print_padding(p->precision, 1, '0');
		}
		else
			print_padding((p->width), 1 - ((p->precision == 0) \
			? 1 : 0), ft_strchr(p->flag, '0') ? '0' : ' ');
		(p->precision != 0 || (p->type == 'o' && ft_strchr(p->flag, \
		'#'))) ? ft_putchar('0') : 0;
	}
	nb += (p->type == 'o' && ft_strchr(p->flag, '#')) ? ft_get_nb(p->width, \
	p->precision, 1) : ft_get_nb2(p->width, p->precision, 1);
	return (nb);
}

char		*code(int n)
{
	char *c;

	if (n == 1)
		c = "0";
	else
		c = (n == 2) ? "0x" : "0X";
	return (c);
}

void		ft_print_sign(char *s, int nb)
{
	if (ft_strchr(s, '+'))
		ft_putchar((nb == 0) ? '-' : '+');
	else if (!ft_strchr(s, '+') && ft_strchr(s, ' '))
		ft_putchar((nb == 0) ? '-' : ' ');
	else
	{
		if (nb == 0)
			ft_putchar('-');
	}
}

long double	abs_f(long double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
