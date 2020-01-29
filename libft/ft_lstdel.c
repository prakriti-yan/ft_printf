/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:50:32 by yyan              #+#    #+#             */
/*   Updated: 2019/10/23 12:55:45 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_link;

	if (!*alst)
		alst = NULL;
	while (*alst)
	{
		next_link = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = next_link;
	}
	alst = NULL;
}
