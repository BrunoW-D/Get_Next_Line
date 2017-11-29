/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:30:03 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/12 12:37:26 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	list = *alst;
	while (list->next)
	{
		(*del)(list->content, list->content_size);
		free(list);
		list = list->next;
	}
	(*del)(list->content, list->content_size);
	free(list);
	*alst = NULL;
}
