/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:52:11 by yyan              #+#    #+#             */
/*   Updated: 2019/10/28 09:44:54 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**w;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	w = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1));
	if (!w || !s)
		return (NULL);
	while (i < ft_word_count(s, c))
	{
		if (!(w[i] = (char*)malloc(sizeof(char) * (ft_word_len(&s[k], c) + 1))))
			return (NULL);
		j = 0;
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			w[i][j++] = s[k++];
		w[i][j] = '\0';
		i++;
	}
	w[i] = NULL;
	return (w);
}
