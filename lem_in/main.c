/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:34:30 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 15:20:26 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_num_extra_ways(t_map *map, int num_ants)
{
	int	start_ways;
	int	end_ways;
	int	result;

	start_ways = lst_count(map->start->links);
	end_ways = lst_count(map->end->links);
	result = (start_ways <= end_ways ? start_ways : end_ways);
	if (num_ants < result)
		result = num_ants;
	return (result);
}

void	remove_duplicate(t_list *paths, t_list **shortest)
{
	while (paths)
	{
		if (list_equals_list(paths->content, (*shortest)->content))
		{
			free_lst_in_lst(shortest);
			*shortest = NULL;
			return ;
		}
		paths = paths->next;
	}
}

void	solve(t_map *map, int num_ants, char *map_string)
{
	int		num_independent_paths;
	t_list	*independent_paths;
	t_list	*shortest_path;

	num_independent_paths = get_num_extra_ways(map, num_ants);
	independent_paths = lem_in(map, num_independent_paths);
	shortest_path = lem_in(map, 0);
	if (independent_paths || shortest_path)
	{
		ft_putendl(map_string + 1);
		ft_putchar('\n');
		remove_duplicate(independent_paths, &shortest_path);
		print_ants_steps(num_ants, shortest_path, independent_paths,
			num_independent_paths);
	}
	else
		ft_putendl("ERROR");
	free_lst_in_lst(&shortest_path);
	free_lst_in_lst(&independent_paths);
}

int		main(void)
{
	int		num_ants;
	t_map	*map;
	char	*map_string;

	map_string = ft_strnew(1);
	num_ants = get_num_ants(&map_string);
	if (num_ants < 1 || !(map = parse_map(1, &map_string)))
	{
		ft_putendl("ERROR");
		free(map_string);
		return (0);
	}
	crop_dead_ends(&map);
	solve(map, num_ants, map_string);
	delete_all(&map);
	free(map_string);
	return (0);
}
