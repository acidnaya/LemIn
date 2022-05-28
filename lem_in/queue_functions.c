/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:52:15 by jfriesen          #+#    #+#             */
/*   Updated: 2019/02/04 16:52:17 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*queue_new(t_room *room, t_queue *prev)
{
	t_queue *new;

	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	new->room = room;
	new->prev = prev;
	if (prev)
		new->distance = prev->distance + 1;
	else
		new->distance = 0;
	new->next = NULL;
	return (new);
}

void		add_elem_to_queue(t_queue **q, t_queue *elem)
{
	elem->next = *q;
	*q = elem;
}

void		push_back_queue(t_queue **all, t_queue *q)
{
	t_queue *ptr;

	ptr = *all;
	if (!ptr)
	{
		*all = q;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = q;
}

void		free_queue(t_queue *q)
{
	t_queue *ptr;

	while (q)
	{
		ptr = q;
		q = q->next;
		free(ptr);
	}
}
