/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:11:39 by yyan              #+#    #+#             */
/*   Updated: 2019/10/24 10:12:54 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tp;
	size_t			i;

	i = 0;
	tp = (unsigned char*)s;
	while (i < n)
	{
		if (tp[i] == (unsigned char)c)
			return (&tp[i]);
		i++;
	}
	return (NULL);
}
