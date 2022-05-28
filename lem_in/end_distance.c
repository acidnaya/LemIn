/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:03:06 by jfriesen          #+#    #+#             */
/*   Updated: 2019/02/04 17:03:07 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_queue_end(t_queue *q, t_queue **q_next, t_map *map)
{
	t_queue *ptr;
	t_list	*links;
	t_queue *elem;

	ptr = q;
	while (ptr)
	{
		links = ptr->room->links;
		while (ptr->room != map->start && links)
		{
			if (!((t_room *)(links->content))->found)
			{
				if (!(elem = queue_new(links->content, ptr)))
					error_exit(q, *q_next, map, NULL);
				elem->room->end_distance = ptr->room->end_distance + 1;
				if (links->content != map->start)
					((t_room *)(links->content))->found = 1;
				add_elem_to_queue(q_next, elem);
			}
			links = links->next;
		}
		ptr = ptr->next;
	}
}

void	find_distance_to_end(t_map *map)
{
	t_queue		*q;
	t_queue		*q_next;
	t_queue		*all;

	all = NULL;
	q_next = NULL;
	q = queue_new(map->end, NULL);
	map->end->found = 1;
	map->end->end_distance = 0;
	while (q)
	{
		create_queue_end(q, &q_next, map);
		push_back_queue(&all, q);
		q = q_next;
		q_next = NULL;
	}
	free_queue(all);
	set_found_to_zero(map);
}
