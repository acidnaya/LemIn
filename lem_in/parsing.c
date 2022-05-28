/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:43:55 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 17:35:36 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

int		get_num_ants(char **map_string)
{
	char	*line;
	long	res;
	int		ret;

	res = -1;
	if ((ret = get_next_line_single_fd(0, &line)) > 0)
	{
		if (map_string)
			*map_string = ft_collect_mapstring(*map_string, line);
		while (line[0] == '#' && ret > 0)
		{
			if (map_string)
				*map_string = ft_collect_mapstring(*map_string, line);
			free(line);
			ret = get_next_line_single_fd(0, &line);
		}
		res = ft_atol(line);
	}
	free(line);
	if (res > 2147483647 || res < -2147483648)
		return (-1);
	return ((int)res);
}

void	process_input_line(char **line, t_map **map, char **map_string)
{
	if ((*line)[0] == '#')
	{
		if (!process_comment(line, *map, map_string))
			delete_all(map);
	}
	else if (!ft_strchr(*line, '-'))
	{
		if (*line && !add_room(*line, *map, 0))
			delete_all(map);
	}
	else if (!add_link(*line, *map))
		delete_all(map);
	if (*line)
		free(*line);
}

t_map	*parse_map(_Bool initial_check, char **map_string)
{
	char	*line;
	t_map	*map;
	int		ret;

	map = initialize_empty_map();
	while (map && ((ret = get_next_line_single_fd(0, &line)) > 0))
	{
		if (map_string)
			*map_string = ft_collect_mapstring(*map_string, line);
		if (line[0] == '\0')
		{
			if (initial_check)
				delete_all(&map);
			else
				break ;
		}
		process_input_line(&line, &map, map_string);
	}
	if (!validate_map(map))
		delete_all(&map);
	return (map);
}
