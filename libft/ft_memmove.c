/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:32:58 by yyan              #+#    #+#             */
/*   Updated: 2019/10/24 10:12:34 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	tmp[len];
	size_t			i;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		tmp[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cdst[i] = tmp[i];
		i++;
	}
	return (cdst);
}
