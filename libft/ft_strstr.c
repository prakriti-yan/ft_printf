/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:19:36 by yyan              #+#    #+#             */
/*   Updated: 2019/10/28 10:07:24 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *nd)
{
	int i;
	int j;

	i = 0;
	if (!nd[0])
		return (char*)(hay);
	while (hay[i])
	{
		j = 0;
		if (hay[i] == nd[j])
		{
			while (nd[j] && hay[i] == nd[j])
			{
				i++;
				j++;
			}
			if (nd[j] == '\0')
				return ((char*)&hay[i - j]);
			else if (hay[i] != nd[j])
				i = i - j;
		}
		i++;
	}
	return (NULL);
}
