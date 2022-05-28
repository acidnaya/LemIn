/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:25:08 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/06 14:36:58 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "visu_hex.h"

const int g_width = 1000;
const int g_height = 800;
const int g_field = 100;

_Bool		init(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr("Couldn't initialize SDL\n");
		return (0);
	}
	else
	{
		*window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, g_width, g_height, SDL_WINDOW_OPENGL);
		if (*window == NULL)
		{
			ft_putstr("Window could not be created!\n");
			return (0);
		}
		else if ((*renderer = SDL_CreateRenderer(*window, -1,
			SDL_RENDERER_ACCELERATED)) == 0)
		{
			ft_putstr("Renderer could not be created!\n");
			return (0);
		}
	}
	return (1);
}

_Bool		load_media(SDL_Surface **surface_ptr, char *media_adress)
{
	*surface_ptr = SDL_LoadBMP(media_adress);
	if (*surface_ptr == NULL)
	{
		ft_putstr("Unable to load image!\n");
		return (0);
	}
	return (1);
}

void		close_sdl(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_DestroyRenderer(*renderer);
	*renderer = NULL;
	SDL_DestroyWindow(*window);
	*window = NULL;
	SDL_Quit();
}

t_point		*get_ant_coordinates(t_map *map, int num_ants)
{
	t_point	*result;
	int		pos;

	result = (t_point *)malloc(sizeof(t_point) * num_ants);
	pos = 0;
	while (pos < num_ants)
	{
		result[pos].x = (map->start)->coor.x;
		result[pos].y = (map->start)->coor.y;
		pos++;
	}
	return (result);
}

int			main(void)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_map			*map;
	int				num_ants;
	t_point			*ant_coordinates;

	window = NULL;
	renderer = NULL;
	num_ants = get_num_ants(0);
	if (!(map = parse_map(0, 0)))
		return (0);
	adapt_map_coordinates(map);
	if (!init(&window, &renderer))
		ft_putstr("Failed to initialize!\n");
	else
	{
		ant_coordinates = get_ant_coordinates(map, num_ants);
		draw_stuff(renderer, map, num_ants, ant_coordinates);
		SDL_Delay(3000);
		draw_ants_transfer(renderer, map, num_ants, ant_coordinates);
	}
	SDL_Delay(10000);
	close_sdl(&window, &renderer);
	delete_all(&map);
	return (0);
}
