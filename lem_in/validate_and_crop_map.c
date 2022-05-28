/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_crop_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:09:13 by msnow-be          #+#    #+#             */
/*   Updated: 2019/01/30 15:14:25 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

_Bool	validate_map(t_map *map)
{
	t_list	*ptr;
	t_room	*room;
	_Bool	has_links;

	if (!map || !(map->rooms) || !(map->start) || !(map->end))
		return (0);
	has_links = 0;
	ptr = map->rooms;
	while (ptr && !has_links)
	{
		room = (t_room *)ptr->content;
		if (room->links)
			has_links = 1;
		ptr = ptr->next;
	}
	return (has_links);
}

void	crop_dead_ends(t_map **map)
{
	t_list	*ptr;
	t_room	*room;
	_Bool	can_continue;

	can_continue = 1;
	while (can_continue)
	{
		ptr = (*map)->rooms;
		while (ptr)
		{
			room = (t_room *)ptr->content;
			if (room != (*map)->start && room != (*map)->end
				&& ft_list_len(room->links) == 1)
			{
				delete_dead_end_by_id(map, room->id);
				break ;
			}
			ptr = ptr->next;
		}
		if (!ptr)
			can_continue = 0;
	}
}
