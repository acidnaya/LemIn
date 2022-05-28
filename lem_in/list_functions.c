/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:57:34 by jfriesen          #+#    #+#             */
/*   Updated: 2019/02/05 17:16:43 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lst_count(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

t_list	*lst_join(t_list *lst, t_list *new)
{
	t_list	*ptr;

	ptr = lst;
	if (!lst)
		return (new);
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (lst);
}

void	free_lst_in_lst(t_list **list)
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*next;

	if (!list || !*list)
		return ;
	lst = *list;
	while (lst)
	{
		lst2 = (t_list *)(lst->content);
		while (lst2)
		{
			next = lst2->next;
			free(lst2);
			lst2 = next;
		}
		next = lst->next;
		free(lst);
		lst = next;
	}
	*list = NULL;
}

t_list	*path_list_maker(t_paths *p)
{
	t_list	*lst;
	t_list	*lst2;
	t_paths *ptr;
	t_queue	*q;

	lst = NULL;
	ptr = p;
	while (ptr)
	{
		lst2 = NULL;
		q = ptr->path;
		while (q)
		{
			ft_lstadd(&lst2, ft_lstnew_nocpy(q->room, sizeof(t_room)));
			q = q->prev;
		}
		ft_lstadd(&lst, ft_lstnew_nocpy(lst2, sizeof(t_list)));
		ptr = ptr->next;
	}
	return (lst);
}

_Bool	list_equals_list(t_list *lhs, t_list *rhs)
{
	while (lhs && rhs)
	{
		if (lhs->content != rhs->content)
			return (0);
		else
		{
			lhs = lhs->next;
			rhs = rhs->next;
		}
	}
	return (1);
}
