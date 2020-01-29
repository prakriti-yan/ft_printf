/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:33:01 by yyan              #+#    #+#             */
/*   Updated: 2019/12/02 16:39:15 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"

typedef struct			s_struct
{
	char				flag[5];
	int					width;
	int					precision;
	char				type;
	char				length[2];
	char				*format;
	va_list				ap;
}						t_struct;

typedef struct			s_float
{
	long double			res;
	long long			value;
	unsigned long long	deci;
	int					l1;
	int					l2;
}						t_float;

int						put_c(t_struct *p, int nb);
int						put_s(t_struct *p, int nb);
int						put_p(t_struct *p, int nb);
char					*convert(char *s, unsigned long long nb, int base);
int						ft_printf(const char *stringformat, ...);
int						put_int(t_struct *p, int nb);
int						put_unsign(t_struct *p, int nb);
int						put_oct(t_struct *p, int nb);
int						put_hex_x(t_struct *p, int nb);
int						put_hex_xuper(t_struct *p, int nb);
void					print_padding(int n, int n2, char c);
int						ft_get_nb(int n1, int n2, int n3);
unsigned long long		get_num(t_struct *p);
void					ft_print_unsign(unsigned long long res);
void					ft_print_sign(char *s, int nb);
int						put_float(t_struct *p, int nb);
unsigned long long		power(int preci);
long double				abs_f(long double nb);
int						sp_atoi(char **s);
int						length(unsigned long long nb);
void					reset_p(t_struct *p);
int						ft_get_nb2(int n1, int n2, int n3);
int						put_percentage(t_struct *p, int nb);
void					ft_print_long(unsigned long long res);
int						put_zero(t_struct *p, int nb);
void					ft_putnstr(char *s, int n);
char					*code(int n);

#endif
