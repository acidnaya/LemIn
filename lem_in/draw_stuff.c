/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:40:36 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 16:57:02 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu_hex.h"

SDL_Rect	*get_coordinates(t_point point)
{
	SDL_Rect			*dst;

	dst = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	dst->x = point.x - 35;
	dst->y = point.y - 28;
	dst->w = 70;
	dst->h = 55;
	return (dst);
}

void		draw_something(SDL_Surface *something, SDL_Rect *dst,
	SDL_Renderer *renderer)
{
	SDL_Texture *texture;

	texture = SDL_CreateTextureFromSurface(renderer, something);
	SDL_RenderCopy(renderer, texture, NULL, dst);
	if (dst)
		free(dst);
}

_Bool		draw_ants(SDL_Renderer *renderer, int num_ants,
	t_point *ant_coordinates)
{
	SDL_Surface	*ant_image;
	int			pos;

	if (!load_media(&ant_image, "graphics_srcs/ant1.bmp"))
	{
		ft_putstr("Failed to load media!\n");
		return (0);
	}
	pos = 0;
	while (pos < num_ants)
	{
		draw_something(ant_image, get_coordinates(ant_coordinates[pos]),
			renderer);
		pos++;
	}
	SDL_FreeSurface(ant_image);
	return (1);
}

void		draw_stuff(SDL_Renderer *renderer, t_map *map, int num_ants,
	t_point *ant_coordinates)
{
	SDL_SetRenderDrawColor(renderer, 44, 27, 22, 255);
	SDL_RenderClear(renderer);
	draw_map(map, renderer);
	draw_ants(renderer, num_ants, ant_coordinates);
	SDL_RenderPresent(renderer);
	SDL_Delay(35);
}
