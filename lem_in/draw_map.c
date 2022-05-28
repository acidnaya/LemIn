/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:55:35 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/05 12:49:34 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu_hex.h"

void	draw_links(t_room *room, SDL_Renderer *renderer)
{
	t_list				*links;
	t_room				*linked;

	links = room->links;
	SDL_SetRenderDrawColor(renderer, 220, 200, 154, 255);
	SDL_RenderFillRect(renderer, get_coordinates(room->coor));
	while (links)
	{
		linked = (t_room *)links->content;
		SDL_RenderDrawLine(renderer, (room->coor).x,
			(room->coor).y, (linked->coor).x, (linked->coor).y);
		links = links->next;
	}
}

_Bool	draw_room_images(t_list *ptr, SDL_Renderer *rend, t_map *map)
{
	SDL_Surface	*entrance;
	SDL_Surface	*exit_img;
	SDL_Surface	*room;
	t_room		*room_ptr;

	if (!load_media(&entrance, "graphics_srcs/entrance.bmp") ||
		!load_media(&exit_img, "graphics_srcs/exit.bmp") ||
		!load_media(&room, "graphics_srcs/room.bmp"))
		return (0);
	while (ptr)
	{
		room_ptr = (t_room *)ptr->content;
		if (room_ptr == map->start)
			draw_something(entrance, get_coordinates(room_ptr->coor), rend);
		else if (room_ptr == map->end)
			draw_something(exit_img, get_coordinates(room_ptr->coor), rend);
		else
			draw_something(room, get_coordinates(room_ptr->coor), rend);
		ptr = ptr->next;
	}
	SDL_FreeSurface(entrance);
	SDL_FreeSurface(exit_img);
	SDL_FreeSurface(room);
	return (1);
}

_Bool	draw_map(t_map *map, SDL_Renderer *renderer)
{
	t_list		*ptr;
	t_room		*room_ptr;

	ptr = map->rooms;
	while (ptr)
	{
		room_ptr = (t_room *)ptr->content;
		draw_links(room_ptr, renderer);
		ptr = ptr->next;
	}
	ptr = map->rooms;
	if (!(draw_room_images(ptr, renderer, map)))
		return (0);
	return (1);
}
