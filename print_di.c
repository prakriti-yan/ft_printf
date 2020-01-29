/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:33:28 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 16:24:13 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"

void			ft_print_long(unsigned long long res)
{
	if (res >= 10)
	{
		ft_print_long(res / 10);
		ft_print_long(res % 10);
	}
	else if (res >= 0 && res < 10)
		ft_putchar(res + '0');
}

long long		get_num_int(t_struct *p)
{
	long long	res;

	if (ft_strstr(p->length, "hh"))
		res = (char)(va_arg(p->ap, int));
	else if (!ft_strstr(p->length, "hh") && ft_strchr(p->length, 'h') != NULL)
		res = (short)(va_arg(p->ap, int));
	else if (ft_strstr(p->length, "ll"))
		res = (long long)(va_arg(p->ap, long long int));
	else if (!ft_strstr(p->length, "ll") && ft_strchr(p->length, 'l') != NULL)
		res = (long)(va_arg(p->ap, long int));
	else
		res = va_arg(p->ap, int);
	return (res);
}

static void		put_int3(t_struct *p, long long res, int len, int width)
{
	if (ft_strchr(p->flag, '0'))
	{
		if ((p->precision > len) || (p->width > len && p->precision != -1))
			print_padding(width, (p->precision > len) ?\
			p->precision : len, ' ');
		ft_print_sign(p->flag, (res >= 0) ? 1 : 0);
		if (p->precision > len)
			print_padding(p->precision, len, '0');
		else if (p->precision == -1 && p->width > len)
			print_padding(width, len, '0');
		if (!(p->precision == 0 && res == 0))
			ft_print_long(res < 0 ? (unsigned long long)(-res) : \
			(unsigned long long)res);
	}
	else
	{
		print_padding(width, (p->precision > len || (p->precision == 0 && \
		res == 0)) ? p->precision : len, ' ');
		ft_print_sign(p->flag, (res >= 0) ? 1 : 0);
		if (p->precision > len)
			print_padding(p->precision, len, '0');
		if (!(p->precision == 0 && res == 0))
			ft_print_long(res < 0 ? (unsigned long long)(-res) : \
			(unsigned long long)res);
	}
}

void			put_int2(t_struct *p, long long res, int len, int width)
{
	ft_print_sign(p->flag, (res >= 0) ? 1 : 0);
	if (p->precision > len)
		print_padding((p->precision), len, '0');
	if (!(p->precision == 0 && res == 0))
		ft_print_long(res < 0 ? (unsigned long long)(-res) : \
		(unsigned long long)res);
	print_padding(width, (p->precision > len) ? p->precision : len, ' ');
	if (p->width > 0 && res == 0 && p->precision == 0)
		ft_putchar(' ');
}

int				put_int(t_struct *p, int nb)
{
	int			len;
	long long	res;
	int			width;

	res = get_num_int(p);
	len = (int)length(res < 0 ? -res : res);
	width = (p->width) - ((ft_strchr(p->flag, ' ') \
	|| ft_strchr(p->flag, '+') || res < 0) ? 1 : 0);
	if (ft_strchr(p->flag, '-') != NULL)
		put_int2(p, res, len, width);
	else if (ft_strchr(p->flag, '-') == NULL)
		put_int3(p, res, len, width);
	if (!(p->width == 0 && p->precision == 0 && res == 0))
		nb += ft_get_nb(p->width, p->precision + ((ft_strchr(p->flag, ' ') \
	|| ft_strchr(p->flag, '+') || (res < 0) ? 1 : 0)), len + ((\
	ft_strchr(p->flag, ' ') || ft_strchr(p->flag, '+') || (res < 0)) ? 1 : 0));
	return (nb);
}
