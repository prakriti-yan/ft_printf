/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:12:18 by yyan              #+#    #+#             */
/*   Updated: 2019/10/18 16:31:19 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nd, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!nd[0])
		return (char*)(hay);
	while (hay[i] && i < len)
	{
		j = 0;
		if (hay[i] == nd[j])
		{
			while (i < len && nd[j] && hay[i] == nd[j])
			{
				i++;
				j++;
			}
			if (nd[j] == '\0')
				return ((char*)&hay[i - j]);
			else if (i < len && hay[i] != nd[j])
				i = i - j;
		}
		i++;
	}
	return (NULL);
}
