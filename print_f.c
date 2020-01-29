/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:33:05 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 17:11:06 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"

void	get_float(t_struct *p, t_float *f, int *preci)
{
	if (ft_strchr(p->length, 'L'))
		f->res = va_arg(p->ap, long double);
	else
		f->res = va_arg(p->ap, double);
	f->value = (long long)f->res;
	*preci = ((p->precision) == -1) ? 6 : (p->precision);
	f->deci = (unsigned long long)(power(*preci) * \
	abs_f((f->res) - (f->value)));
	f->l1 = length(f->deci);
	f->deci += (((power(*preci) * abs_f(f->res - f->value)) - ((unsigned \
	long long)(power(*preci) * abs_f((f->res - f->value))))) >= 0.5) ? 1 : 0;
	f->l2 = length(f->deci);
	if (f->value < 0)
		f->value -= (((f->l2 > f->l1) && f->deci >= power(*preci)) || \
		(*preci == 0 && abs_f(f->res - f->value) > 0.5)) ? 1 : 0;
	else
		f->value += (((f->l2 > f->l1) && f->deci >= power(*preci)) || \
		(*preci == 0 && abs_f(f->res - f->value) > 0.5)) ? 1 : 0;
	f->deci = ((f->l2 > f->l1) && f->deci >= power(*preci)) ? 0 : f->deci;
}

void	ft_print_deci(unsigned long long deci, int preci)
{
	int	size;

	size = length(deci);
	while (preci > size)
	{
		ft_putchar('0');
		preci--;
	}
	if (deci >= 10)
	{
		ft_print_unsign(deci / 10);
		ft_print_unsign(deci % 10);
	}
	else if (deci >= 0 && deci < 10)
		ft_putchar(deci + '0');
}

void	put_float2(t_struct *p, t_float *f, int len, int preci)
{
	if (ft_strchr(p->flag, '0'))
	{
		ft_print_sign(p->flag, (f->res >= 0) ? 1 : 0);
		print_padding((p->width) - ((ft_strchr(p->flag, ' ') \
		|| ft_strchr(p->flag, '+') || f->res < 0) ? 1 : 0), len, '0');
		ft_print_long((f->value < 0) ? (unsigned long long)-(f->value) : \
		(unsigned long long)(f->value));
		(((p->precision) != 0) || (ft_strchr(p->flag, '#'))) ? \
		ft_putchar('.') : 0;
		((p->precision) != 0) ? ft_print_deci(f->deci, preci) : 0;
	}
	else
	{
		print_padding((p->width) - ((ft_strchr(p->flag, ' ') || \
		ft_strchr(p->flag, '+') || f->res < 0) ? 1 : 0), len, ' ');
		ft_print_sign(p->flag, (f->res >= 0) ? 1 : 0);
		ft_print_long((f->value < 0) ? (unsigned long long)(-f->value) :\
		(unsigned long long)f->value);
		(((p->precision) != 0) || (ft_strchr(p->flag, '#'))) ? \
		ft_putchar('.') : 0;
		((p->precision) != 0) ? ft_print_deci(f->deci, preci) : 0;
	}
}

int		put_float(t_struct *p, int nb)
{
	int			len;
	int			width;
	int			preci;
	t_float		f;

	get_float(p, &f, &preci);
	len = (int)length((f.value < 0) ? (unsigned long long)-f.value : \
	(unsigned long long)f.value) + preci;
	len += ((p->precision) == 0 && !(ft_strchr(p->flag, '#'))) ? 0 : 1;
	width = (p->width) - ((ft_strchr(p->flag, ' ') \
	|| ft_strchr(p->flag, '+') || f.res < 0) ? 1 : 0);
	if (ft_strchr(p->flag, '-') != NULL)
	{
		ft_print_sign(p->flag, (f.res >= 0) ? 1 : 0);
		ft_print_long((f.value < 0) ? (unsigned long long)-(f.value) : \
		(unsigned long long)(f.value));
		(((p->precision) != 0) || (ft_strchr(p->flag, '#'))) ? \
		ft_putchar('.') : 0;
		((p->precision) != 0) ? ft_print_deci(f.deci, preci) : 0;
		print_padding(width, len, ' ');
	}
	else if (ft_strchr(p->flag, '-') == NULL)
		put_float2(p, &f, len, preci);
	return (nb += ft_get_nb(p->width, len, len));
}
