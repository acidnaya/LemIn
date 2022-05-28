/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:15:53 by jfriesen          #+#    #+#             */
/*   Updated: 2019/02/04 19:15:56 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_exit(t_queue *q, t_queue *q_next, t_map *map, t_paths *p)
{
	free_queue(q);
	q = NULL;
	free_queue(q_next);
	q_next = NULL;
	if (p)
		free_paths(&p);
	delete_all(&map);
	ft_putendl("ERROR");
	exit(0);
}
