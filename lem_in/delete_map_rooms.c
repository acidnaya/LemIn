/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_map_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:10:16 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 16:56:21 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_deleter(void *content, size_t size)
{
	t_room *room;

	if (size == 0)
		return ;
	room = (t_room *)content;
	free(room->id);
	room->id = (NULL);
	if (room->links)
		ft_lstdel_nocpy(&(room->links));
	free(room);
	room = (NULL);
}

void	delete_all(t_map **map)
{
	if (!map || !*map)
		return ;
	if ((*map)->rooms)
		ft_lstdel(&((*map)->rooms), room_deleter);
	free(*map);
	*map = NULL;
}

void	remove_room_from_links(t_list **links, char *id)
{
	t_list	*ptr;
	t_list	*prev;
	t_room	*room;

	ptr = *links;
	prev = (NULL);
	while (ptr)
	{
		room = (t_room *)ptr->content;
		if (room->id == id)
		{
			if (!prev)
				*links = ptr->next;
			else
				prev->next = ptr->next;
			ft_lstdelone_nocpy(&ptr);
			return ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}

void	delete_dead_end_by_id(t_map **map, char *id)
{
	t_list	*ptr;
	t_list	*prev;
	t_room	*room;
	t_room	*linked_room;

	ptr = (*map)->rooms;
	prev = (NULL);
	while (ptr)
	{
		room = (t_room *)ptr->content;
		if (room->id == id)
		{
			linked_room = (t_room *)(room->links)->content;
			remove_room_from_links(&(linked_room->links), id);
			if (!prev)
				(*map)->rooms = ptr->next;
			else
				prev->next = ptr->next;
			ft_lstdelone(&ptr, room_deleter);
			break ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}
