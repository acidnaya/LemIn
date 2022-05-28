/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:19:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/07 17:17:12 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct		s_room
{
	char			*id;
	char			found;
	int				end_distance;
	t_point			coor;
	t_list			*links;
}					t_room;

typedef struct		s_map
{
	t_list			*rooms;
	t_room			*start;
	t_room			*end;
}					t_map;

typedef struct		s_queue
{
	t_room			*room;
	struct s_queue	*prev;
	int				distance;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_paths
{
	t_queue			*path;
	t_queue			*all;
	int				num;
	int				crossings;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_ant_route
{
	t_list			*path;
	int				start_time;
}					t_ant_route;

# define BUFF_SIZE 5

int					get_next_line_single_fd(const int fd, char **line);
_Bool				add_link(char *line, t_map *map);
_Bool				add_room(char *line, t_map *map, char special_id);
t_ant_route			*assign_routes_to_ants(t_list *shortest, t_list *other,
						int num_ants, int min_independent_len);
void				clear_string_array(char **array);
char				*ft_collect_mapstring(char *s1, char *s2);
void				crop_dead_ends(t_map **map);
void				delete_all(t_map **map);
void				delete_dead_end_by_id(t_map **map, char *id);
t_room				*find_room(char *name, t_map *map);
long				ft_atol(char *str);
int					ft_list_len(t_list *lst);
int					get_num_ants(char **map_string);
t_map				*initialize_empty_map(void);
void				ft_lstdel_nocpy(t_list **alst);
void				ft_lstdelone_nocpy(t_list **alst);
t_list				*ft_lstnew_nocpy(void const *content, size_t content_size);
_Bool				list_equals_list(t_list *lhs, t_list *rhs);
t_map				*parse_map(_Bool initial_check, char **map_string);
_Bool				process_comment(char **line, t_map *map, char **map_string);
void				room_deleter(void *content, size_t size);
_Bool				validate_map(t_map *map);
void				dfs(t_map *map);
t_paths				*bfs(t_map *map, int n);
t_list				*lem_in(t_map *map, int n);
void				find_distance_to_end(t_map *map);
_Bool				print_ants_steps(int num_ants, t_list *shortest,
					t_list *other,
					int num_extra_ways);
void				free_lst_in_lst(t_list **list);
t_list				*path_list_maker(t_paths *p);
t_paths				*create_path(t_queue *elem);
void				add_elem_to_paths(t_queue *elem, t_paths **p, t_map *map);
void				free_paths(t_paths **p);
void				delete_one_path(t_paths **p, t_paths **ptr);
void				complete_paths(t_paths **p, t_map *map);
t_queue				*queue_new(t_room *room, t_queue *prev);
void				add_elem_to_queue(t_queue **q, t_queue *elem);
void				push_back_queue(t_queue **all, t_queue *q);
void				free_queue(t_queue *q);
void				set_crossings_to_zero(t_paths *p);
void				count_crossings(t_paths **p, t_map *map);
int					delete_max_crossings(t_paths **p);
int					lst_count(t_list *lst);
t_list				*lst_join(t_list *lst, t_list *new);
void				free_lst_in_lst(t_list **list);
t_list				*path_list_maker(t_paths *p);
void				set_found_to_zero(t_map *map);
void				set_all_to_zero(t_map *map);
void				set_found_paths_to_one(t_paths *p, t_map *map);
void				set_found_paths_to_minus(t_paths *p, t_map *map);
void				error_exit(t_queue *q, t_queue *q_next, t_map *map,
					t_paths *p);
char				**ft_strsplit_symbols(char *str, char *c);
int					create_queue(t_queue *q, t_queue **q_next, t_map *map,
							t_paths **p);
#endif
