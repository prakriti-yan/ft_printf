/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:32:37 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 17:08:00 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"

int			put_c(t_struct *p, int nb)
{
	if (ft_strchr(p->flag, '-') != NULL)
	{
		ft_putchar(va_arg(p->ap, int));
		print_padding(p->width, 1, ' ');
	}
	if (ft_strchr(p->flag, '-') == NULL)
	{
		print_padding(p->width, 1, ' ');
		ft_putchar(va_arg(p->ap, int));
	}
	nb += p->width ? p->width : 1;
	return (nb);
}

int			put_s_null(t_struct *p, int nb, int preci, char *s)
{
	if (s == NULL)
	{
		if (ft_strchr(p->flag, '-') != NULL)
		{
			ft_putnstr("(null)", p->precision);
			(p->width > 0) ? print_padding(p->width, preci, ' ') : 0;
		}
		if (ft_strchr(p->flag, '-') == NULL)
		{
			(p->width > 0) ? print_padding(p->width, preci, ' ') : 0;
			ft_putnstr("(null)", p->precision);
		}
	}
	else
		print_padding(p->width, 0, ' ');
	nb += (s == NULL) ? ft_get_nb(p->width, p->precision, \
	ft_strlen("(null)")) : p->width;
	return (nb);
}

static void	put_s2(t_struct *p, int preci, char *s)
{
	if (ft_strchr(p->flag, '-') != NULL)
	{
		if (p->width > 0)
			(ft_strcmp(s, "")) ? ft_putnstr(s, p->precision) : \
			print_padding(p->precision, 0, ' ');
		else
			(ft_strcmp(s, "")) ? ft_putnstr(s, p->precision) : 0;
		(p->width > 0) ? print_padding(p->width, preci, ' ') : 0;
	}
	if (ft_strchr(p->flag, '-') == NULL)
	{
		(p->width > 0) ? print_padding(p->width, preci, ' ') : 0;
		if (p->width > 0)
			(ft_strcmp(s, "")) ? ft_putnstr(s, p->precision) : \
			print_padding(p->precision, 0, ' ');
		else
			(ft_strcmp(s, "")) ? ft_putnstr(s, p->precision) : 0;
	}
}

int			put_s(t_struct *p, int nb)
{
	char	*s;
	int		preci;
	int		len;

	s = va_arg(p->ap, char*);
	len = (s == NULL) ? 6 : ft_strlen(s);
	preci = 0;
	preci = ((p->precision != -1 && p->precision < len) || \
	(!ft_strcmp(s, "") && p->precision != -1)) ? p->precision : len;
	if (s == NULL || !ft_strcmp(s, "\0"))
		nb = put_s_null(p, nb, preci, s);
	else
	{
		put_s2(p, preci, s);
		nb += ft_get_nb2(p->width, p->precision, ft_strlen(s));
	}
	return (nb);
}

int			put_p(t_struct *p, int nb)
{
	char s[100];
	char *ptr;

	ptr = va_arg(p->ap, void *);
	(ptr == 0) ? ft_strcpy(s, "0") : convert(s, (unsigned long long)ptr, 16);
	if (ft_strchr(p->flag, '-') != NULL)
	{
		ft_putstr("0x");
		ft_putstr(s);
		print_padding(p->width, ft_strlen(s) + 2, ' ');
	}
	if (ft_strchr(p->flag, '-') == NULL)
	{
		print_padding(p->width, ft_strlen(s) + 2, ' ');
		ft_putstr("0x");
		ft_putstr(s);
	}
	nb += ft_get_nb(p->width, ft_strlen(s) + 2, ft_strlen(s) + 2);
	return (nb);
}
