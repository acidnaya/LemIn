/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:00:40 by jfriesen          #+#    #+#             */
/*   Updated: 2019/02/04 17:00:42 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_found_to_zero(t_map *map)
{
	t_list	*ptr;

	ptr = map->rooms;
	while (ptr)
	{
		if (((t_room *)(ptr->content))->found != -1)
			((t_room *)(ptr->content))->found = 0;
		ptr = ptr->next;
	}
}

void		set_all_to_zero(t_map *map)
{
	t_list	*ptr;

	ptr = map->rooms;
	while (ptr)
	{
		((t_room *)(ptr->content))->found = 0;
		ptr = ptr->next;
	}
}

void		set_found_paths_to_one(t_paths *p, t_map *map)
{
	t_paths *ptr;
	t_queue *qptr;

	ptr = p;
	while (ptr)
	{
		qptr = ptr->path;
		if (qptr && qptr->room == map->end)
		{
			while (qptr)
			{
				if (qptr->room->found != -1)
					qptr->room->found = 1;
				qptr = qptr->prev;
			}
		}
		ptr = ptr->next;
	}
}

void		set_found_paths_to_minus(t_paths *p, t_map *map)
{
	t_paths *ptr;
	t_queue *qptr;

	ptr = p;
	while (ptr)
	{
		qptr = ptr->path;
		while (qptr)
		{
			if (qptr->room != map->end)
				qptr->room->found = -1;
			qptr = qptr->prev;
		}
		ptr = ptr->next;
	}
}
