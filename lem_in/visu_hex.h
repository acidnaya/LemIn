/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:57:30 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 16:34:26 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

# include "/Users/msnow-be/brew/Cellar/sdl2/2.0.9/include/SDL2/SDL.h"

extern const int g_width;
extern const int g_height;
extern const int g_field;

# define BUFF_SIZE 5

int			get_next_line_single_fd(const int fd, char **line);

void		adapt_map_coordinates(t_map *map);
void		draw_ants_transfer(SDL_Renderer *renderer, t_map *map,
				int num_ants, t_point *ant_coordinates);
_Bool		draw_map(t_map *map, SDL_Renderer *renderer);
void		draw_something(SDL_Surface *something, SDL_Rect *dst,
				SDL_Renderer *renderer);
void		draw_stuff(SDL_Renderer *renderer, t_map *map, int num_ants,
				t_point *ant_coordinates);
SDL_Rect	*get_coordinates(t_point point);
_Bool		load_media(SDL_Surface **surface_ptr, char *media_adress);

#endif
