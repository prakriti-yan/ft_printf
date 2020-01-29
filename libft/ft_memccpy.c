/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:52:20 by yyan              #+#    #+#             */
/*   Updated: 2019/10/24 09:57:44 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const \
		void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*s2;

	i = 0;
	s = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	if (s == NULL || s2 == NULL)
		return (NULL);
	while (i < n)
	{
		if (s2[i] != (unsigned char)c)
		{
			s[i] = s2[i];
			i++;
		}
		if (s2[i] == (unsigned char)c)
		{
			s[i] = s2[i];
			dst = s;
			return (&s[i + 1]);
		}
	}
	dst = s;
	return (NULL);
}
