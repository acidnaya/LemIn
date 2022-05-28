/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_empty_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:01 by msnow-be          #+#    #+#             */
/*   Updated: 2019/01/29 14:25:01 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_map	*initialize_empty_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		map->rooms = (NULL);
		map->start = (NULL);
		map->end = (NULL);
	}
	return (map);
}
