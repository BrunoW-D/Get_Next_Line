/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:42:19 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/12 14:46:43 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *first_new;
	t_list *new;

	list = lst;
	first_new = (t_list*)malloc(sizeof(t_list));
	new = (t_list*)malloc(sizeof(t_list));
	first_new = (*f)(list);
	new = first_new;
	list = list->next;
	while (list->next)
	{
		new->next = (*f)(list);
		new = new->next;
		list = list->next;
	}
	new->next = (*f)(list);
	free(new);
	return (first_new);
}
