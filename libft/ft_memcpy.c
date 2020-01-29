/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:17:03 by yyan              #+#    #+#             */
/*   Updated: 2019/10/25 16:48:54 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*s2;

	i = 0;
	s = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	if (!s && !s2)
		return (NULL);
	while (i < n)
	{
		s[i] = s2[i];
		i++;
	}
	return (dst);
}
