/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:22:38 by yyan              #+#    #+#             */
/*   Updated: 2019/10/24 09:57:39 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t i;

	i = 0;
	while (i < maxlen && s[i])
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const \
		char *src, size_t dstsize)
{
	size_t srclen;
	size_t dstlen;

	dstlen = ft_strnlen(dst, dstsize);
	srclen = ft_strlen(src);
	if (dstlen == dstsize)
		return (dstsize + srclen);
	if (srclen < dstsize - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
