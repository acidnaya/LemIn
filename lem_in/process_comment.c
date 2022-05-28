/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:28:05 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 17:36:53 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

_Bool	skip_comments(char **line, int *ret, char **map_string)
{
	while ((*line)[0] == '#' && *ret > 0)
	{
		if (map_string)
			*map_string = ft_collect_mapstring(*map_string, *line);
		if (!ft_strncmp(*line + 2, "start\0", 6) || !ft_strncmp(*line + 2,
			"end\0", 4))
		{
			free(*line);
			*line = NULL;
			return (0);
		}
		free(*line);
		*line = NULL;
		*ret = get_next_line_single_fd(0, line);
	}
	return (1);
}

_Bool	process_comment(char **line, t_map *map, char **map_string)
{
	int		ret;
	char	room_type;

	if ((*line)[1] == '#')
	{
		if (!ft_strncmp(*line + 2, "start\0", 6) || !ft_strncmp(*line + 2,
			"end\0", 4))
		{
			room_type = (*line)[2];
			free(*line);
			*line = NULL;
			ret = get_next_line_single_fd(0, line);
			if (!(skip_comments(line, &ret, map_string)))
				return (0);
			if ((ret <= 0 || !add_room(*line, map, room_type)))
				return (0);
			else if (map_string)
				*map_string = ft_collect_mapstring(*map_string, *line);
		}
	}
	return (1);
}
