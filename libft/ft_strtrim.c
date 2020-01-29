/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:22:12 by yyan              #+#    #+#             */
/*   Updated: 2019/10/28 09:48:17 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	*ft_getsize(char const *s)
{
	int i;
	int mk1;
	int mk2;
	int *ar;

	i = 0;
	mk1 = 0;
	mk2 = 0;
	if (!(ar = (int*)malloc(sizeof(int) * 3)))
		return (NULL);
	while (ft_iswhsp(s[i]) == 1 && s[i])
		i++;
	if (ft_iswhsp(s[i]) == 0 && s[i])
		mk1 = i;
	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_iswhsp(s[i]) == 1)
		i--;
	if (ft_iswhsp(s[i]) == 0 && i >= 0)
		mk2 = i;
	ar[0] = mk1;
	ar[1] = mk2;
	ar[2] = mk2 - mk1;
	return (ar);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		*ar;
	int		j;

	ar = ft_getsize(s);
	i = ar[0];
	j = 0;
	str = (char*)malloc(sizeof(char) * (ar[2] + 1));
	if (!str)
		return (NULL);
	if (ar[0] == 0 && ar[1] == 0 && ar[2] == 0)
		return ("");
	while (i <= ar[1])
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
