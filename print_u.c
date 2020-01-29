/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:33:17 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 17:15:20 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"

int					ft_get_ustrlen(unsigned long long res)
{
	int len;

	len = 1;
	while ((res /= 10) > 0)
		len++;
	return (len);
}

void				ft_print_unsign(unsigned long long res)
{
	if (res >= 10)
	{
		ft_print_unsign(res / 10);
		ft_print_unsign(res % 10);
	}
	else if (res >= 0 && res < 10)
		ft_putchar(res + '0');
}

unsigned long long	get_num(t_struct *p)
{
	unsigned long long	res;

	if (ft_strstr(p->length, "hh"))
		res = (unsigned char)(va_arg(p->ap, unsigned int));
	else if (!ft_strstr(p->length, "hh") && ft_strchr(p->length, 'h') != NULL)
		res = (unsigned short)(va_arg(p->ap, unsigned int));
	else if (ft_strstr(p->length, "ll"))
		res = (unsigned long long)(va_arg(p->ap, unsigned long long int));
	else if (!ft_strstr(p->length, "ll") && ft_strchr(p->length, 'l') != NULL)
		res = (unsigned long)(va_arg(p->ap, unsigned long int));
	else
		res = va_arg(p->ap, unsigned int);
	return (res);
}

static void			put_unsign2(t_struct *p, int len, unsigned long long res)
{
	if (ft_strchr(p->flag, '0'))
	{
		if ((p->precision > len) || (p->width > len && p->precision != -1))
			print_padding(p->width, (p->precision > len) ? \
			p->precision : len, ' ');
		if (p->precision > len)
			print_padding(p->precision, len, '0');
		else if (p->precision == -1 && p->width > len)
			print_padding((p->width), len, '0');
		(res == 0 && p->width > 0) ? ft_putchar(' ') : ft_print_unsign(res);
	}
	else
	{
		print_padding((p->width), (p->precision > len) ? \
		p->precision : len, ' ');
		if (p->precision > len)
			print_padding((p->precision), len, '0');
		(res == 0 && p->width > 0) ? ft_putchar(' ') : ft_print_unsign(res);
	}
}

int					put_unsign(t_struct *p, int nb)
{
	unsigned long long	res;
	int					len;

	res = get_num(p);
	len = ft_get_ustrlen(res);
	if (res == 0)
		nb = put_zero(p, nb);
	else
	{
		if (ft_strchr(p->flag, '-') != NULL)
		{
			if (p->precision > len)
				print_padding((p->precision), len, '0');
			(res == 0 && p->width > 0) ? ft_putchar(' ') : ft_print_unsign(res);
			print_padding((p->width), (p->precision > len) ? \
			p->precision : len, ' ');
		}
		else if (ft_strchr(p->flag, '-') == NULL)
			put_unsign2(p, len, res);
		nb += ft_get_nb(p->width, p->precision, len);
	}
	return (nb);
}
