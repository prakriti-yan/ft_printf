/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:44:04 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 14:31:56 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"

static void	get_format2(t_struct *p)
{
	int i;

	i = 0;
	if (*(p->format) == 'L')
	{
		*(p->length) = 'L';
		p->format++;
	}
	while (*(p->format) == 'h')
		p->length[i++] = *(p->format++);
	while (*(p->format) == 'l')
		p->length[i++] = *(p->format++);
	if (*(p->format) == 'c' || *(p->format) == 'p' || *(p->format) == 'o' ||\
	*(p->format) == 's' || *(p->format) == 'd' || *(p->format) == 'i' ||\
	*(p->format) == 'x' || *(p->format) == 'X' || *(p->format) == 'u' ||\
	*(p->format) == 'f' || *(p->format) == '%')
	{
		p->type = *(p->format);
		p->format++;
	}
}

void		get_format(t_struct *p)
{
	int i;

	i = 0;
	while (*(p->format) && (*(p->format) == '0' || *(p->format) == '+' \
	|| *(p->format) == '-' || *(p->format) == ' ' || *(p->format) == '#'))
		p->flag[i++] = *(p->format++);
	if (ft_isdigit(*(p->format)) || *(p->format) == '*')
	{
		if (*(p->format) >= '1')
			p->width = sp_atoi(&p->format);
		else if (*(p->format) == '*')
			p->width = va_arg(p->ap, int);
		p->format++;
	}
	if (*(p->format) == '.')
	{
		p->format++;
		p->precision = sp_atoi(&p->format);
		p->format++;
	}
	get_format2(p);
}

int			print_arg(t_struct *p, int nb)
{
	if (p->type == 'c')
		nb = put_c(p, nb);
	else if (p->type == 's')
		nb = put_s(p, nb);
	else if (p->type == 'p')
		nb = put_p(p, nb);
	else if (p->type == 'i' || p->type == 'd')
		nb = put_int(p, nb);
	else if (p->type == 'u')
		nb = put_unsign(p, nb);
	else if (p->type == 'o')
		nb = put_oct(p, nb);
	else if (p->type == 'x')
		nb = put_hex_x(p, nb);
	else if (p->type == 'X')
		nb = put_hex_xuper(p, nb);
	else if (p->type == 'f')
		nb = put_float(p, nb);
	else if (p->type == '%')
		nb = put_percentage(p, nb);
	return (nb);
}

int			ft_printf(const char *format, ...)
{
	t_struct	stru;
	int			nb;

	nb = 0;
	stru.format = (char*)format;
	va_start(stru.ap, format);
	while (*stru.format)
	{
		if (*stru.format == '%')
		{
			stru.format++;
			reset_p(&stru);
			get_format(&stru);
			nb = print_arg(&stru, nb);
		}
		while (*stru.format != '%' && *stru.format)
		{
			ft_putchar(*stru.format);
			stru.format++;
			nb++;
		}
	}
	va_end(stru.ap);
	return (nb);
}
