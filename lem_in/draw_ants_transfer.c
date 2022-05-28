/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants_transfer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:29:31 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 15:17:24 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu_hex.h"

void		update_ants_coordinates(t_point *coordinates, t_point *velocities,
	int num_ants, int animation_iters)
{
	int ant_index;

	ant_index = 0;
	while (ant_index < num_ants)
	{
		coordinates[ant_index].x += (velocities[ant_index].x) / animation_iters;
		coordinates[ant_index].y += (velocities[ant_index].y) / animation_iters;
		ant_index++;
	}
}

t_point		*get_ants_velocities(char *line, t_point *coordinates, t_map *map,
	int num_ants)
{
	char	**moves;
	char	*move;
	int		pos;
	int		ant_index;
	t_point	*velocities;

	moves = ft_strsplit(line, ' ');
	pos = 0;
	velocities = (t_point *)malloc(sizeof(t_point) * num_ants);
	ft_bzero(velocities, sizeof(t_point) * num_ants);
	while (moves[pos] != 0)
	{
		move = moves[pos];
		ant_index = ft_atoi(++move) - 1;
		while (*move != '-')
			move++;
		move++;
		velocities[ant_index].x = ((find_room(move, map))->coor).x -
			(coordinates[ant_index]).x;
		velocities[ant_index].y = ((find_room(move, map))->coor).y -
			(coordinates[ant_index]).y;
		pos++;
	}
	clear_string_array(moves);
	return (velocities);
}

void		draw_ants_transfer(SDL_Renderer *renderer, t_map *map,
	int num_ants, t_point *ant_coordinates)
{
	int		ret;
	char	*line;
	t_point	*velocities;
	int		animation_iters;
	int		iter_num;

	animation_iters = 20;
	while ((ret = get_next_line_single_fd(0, &line)) > 0)
	{
		velocities = get_ants_velocities(line, ant_coordinates, map, num_ants);
		iter_num = 0;
		while (iter_num++ < animation_iters)
		{
			update_ants_coordinates(ant_coordinates, velocities, num_ants,
				animation_iters);
			draw_stuff(renderer, map, num_ants, ant_coordinates);
		}
		free(velocities);
	}
}
