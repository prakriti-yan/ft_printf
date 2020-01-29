/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:32:36 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 15:22:31 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"

static void	ft_putstr_up(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	ft_putstr(s);
}

static void	put_ox_2(t_struct *p, int len, char *s, int n)
{
	char *c;

	c = code(n);
	if (ft_strchr(p->flag, '0'))
	{
		if ((p->precision > len) || (p->width > len && p->precision != -1))
			print_padding(p->width, (p->precision > len) ? \
			p->precision : len, ' ');
		(ft_strchr(p->flag, '#')) ? ft_putstr(c) : 0;
		if (p->precision > len)
			print_padding(p->precision, len, '0');
		else if (p->precision == -1 && p->width > len)
			print_padding(p->width, len, '0');
		(n != 3) ? ft_putstr(s) : ft_putstr_up(s);
	}
	else
	{
		print_padding((p->width), (p->precision > len) ? \
		p->precision : len, ' ');
		(ft_strchr(p->flag, '#')) ? ft_putstr(c) : 0;
		print_padding(p->precision, len, '0');
		(n != 3) ? ft_putstr(s) : ft_putstr_up(s);
	}
}

int			put_oct(t_struct *p, int nb)
{
	char				s[100];
	unsigned long long	res;
	int					len;

	res = get_num(p);
	if (res == 0)
		nb = put_zero(p, nb);
	else
	{
		convert(s, res, 8);
		len = ft_strlen(s) + ((ft_strchr(p->flag, '#')) ? 1 : 0);
		if (ft_strchr(p->flag, '-') != NULL)
		{
			(ft_strchr(p->flag, '#')) ? ft_putchar('0') : 0;
			if (p->precision > (int)ft_strlen(s))
				print_padding((p->precision), (int)ft_strlen(s), '0');
			ft_putstr(s);
			print_padding(p->width, (p->precision > len) ? \
			p->precision : len, ' ');
		}
		else if (ft_strchr(p->flag, '-') == NULL)
			put_ox_2(p, len, s, 1);
		nb = nb + ft_get_nb(p->width, p->precision, len);
	}
	return (nb);
}

int			put_hex_x(t_struct *p, int nb)
{
	char				s[100];
	unsigned long long	res;
	int					len;

	res = get_num(p);
	if (res == 0)
		nb = put_zero(p, nb);
	else
	{
		convert(s, res, 16);
		len = ft_strlen(s) + ((ft_strchr(p->flag, '#')) ? 2 : 0);
		if (ft_strchr(p->flag, '-') != NULL)
		{
			(ft_strchr(p->flag, '#')) ? ft_putstr("0x") : 0;
			if (p->precision > (int)ft_strlen(s))
				print_padding((p->precision), (int)ft_strlen(s), '0');
			ft_putstr(s);
			print_padding((p->width), (p->precision > len) ? \
			p->precision : len, ' ');
		}
		else if (ft_strchr(p->flag, '-') == NULL)
			put_ox_2(p, len, s, 2);
		nb = nb + ft_get_nb(p->width, p->precision, len);
	}
	return (nb);
}

int			put_hex_xuper(t_struct *p, int nb)
{
	char				s[100];
	unsigned long long	res;
	int					len;

	res = get_num(p);
	if (res == 0)
		nb = put_zero(p, nb);
	else
	{
		convert(s, res, 16);
		len = ft_strlen(s) + ((ft_strchr(p->flag, '#')) ? 2 : 0);
		if (ft_strchr(p->flag, '-') != NULL)
		{
			(ft_strchr(p->flag, '#')) ? ft_putstr("0X") : 0;
			if (p->precision > (int)ft_strlen(s))
				print_padding((p->precision), (int)ft_strlen(s), '0');
			ft_putstr_up(s);
			print_padding((p->width), (p->precision > len) ? \
			p->precision : len, ' ');
		}
		else if (ft_strchr(p->flag, '-') == NULL)
			put_ox_2(p, len, s, 3);
		nb = nb + ft_get_nb(p->width, p->precision, len);
	}
	return (nb);
}
