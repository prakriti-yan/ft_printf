/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:03:51 by yyan              #+#    #+#             */
/*   Updated: 2019/10/22 18:12:23 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		result;

	result = 0;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			result = i;
			return (char*)&s[i];
		}
		i--;
	}
	return (NULL);
}
