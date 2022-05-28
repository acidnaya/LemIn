/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:45:06 by msnow-be          #+#    #+#             */
/*   Updated: 2019/01/30 14:45:22 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

t_room	*find_room(char *name, t_map *map)
{
	t_list	*list_ptr;
	t_room	*room_ptr;

	list_ptr = map->rooms;
	while (list_ptr)
	{
		room_ptr = (t_room *)list_ptr->content;
		if (!ft_strcmp(name, room_ptr->id))
			return (room_ptr);
		list_ptr = list_ptr->next;
	}
	return (NULL);
}
