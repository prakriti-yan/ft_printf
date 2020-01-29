/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:47:59 by yyan              #+#    #+#             */
/*   Updated: 2019/10/24 15:54:48 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (!s1 && !s2)
		return (NULL);
	else
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
