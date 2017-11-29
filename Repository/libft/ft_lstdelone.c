/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:29:23 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/12 13:37:11 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	list = *alst;
	*alst = list->next;
	(*del)(list->content, list->content_size);
	free(list);
	ft_memdel((void**)alst);
}
