/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:55:03 by jfriesen          #+#    #+#             */
/*   Updated: 2019/02/07 17:17:35 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths		*create_path(t_queue *elem)
{
	t_paths *new;

	new = (t_paths *)malloc(sizeof(t_paths));
	new->path = elem;
	new->num = 0;
	new->crossings = 0;
	new->next = NULL;
	return (new);
}

void		add_elem_to_paths(t_queue *elem, t_paths **p, t_map *map)
{
	t_paths *new;

	new = create_path(elem);
	if (*p)
	{
		if (elem->room == map->end)
			new->num = (*p)->num + 1;
		else
			new->num = (*p)->num;
	}
	else
	{
		if (elem->room == map->end)
			new->num = 1;
		else
			new->num = 0;
	}
	new->next = *p;
	*p = new;
}

void		free_paths(t_paths **p)
{
	t_paths *ptr;

	while (*p)
	{
		ptr = *p;
		*p = (*p)->next;
		free(ptr->path);
		ptr->path = NULL;
		free(ptr);
	}
}

void		delete_one_path(t_paths **p, t_paths **ptr)
{
	t_paths *del;
	t_paths *prev;

	if (*ptr == *p)
	{
		*p = (*p)->next;
		free((*ptr)->path);
		(*ptr)->path = NULL;
		free(*ptr);
		*ptr = NULL;
	}
	else
	{
		del = *p;
		while (del != *ptr)
		{
			prev = del;
			del = del->next;
		}
		prev->next = del->next;
		free(del->path);
		free(del);
		del = NULL;
	}
}

void		complete_paths(t_paths **p, t_map *map)
{
	t_paths *ptr;
	t_paths *next;

	ptr = *p;
	while (ptr && ptr->path)
	{
		next = ptr->next;
		if (ptr->path->room != map->end)
		{
			if (!ptr->path->room->found)
				delete_one_path(p, &ptr);
		}
		ptr = next;
	}
}
