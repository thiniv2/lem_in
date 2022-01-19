/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:41 by epalomak          #+#    #+#             */
/*   Updated: 2022/01/19 14:57:33 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_lem
{
	long		n_ants;
	char		*start;
	char		*end;
	char		**map;
	int			room_nbr;
	int			i;
	int			y;
	int			link_index;
	int			**tmp_paths;
	int			**paths;
	int			end_index;
	int			boole;
}				t_lem;

typedef struct s_paths
{
	int			path_len;
	int			start_room;
	int			ants;
}				t_paths;

typedef struct s_ants
{
	int			ant_nbr;
	int			path_index;
	int			curr_room;
	int			is_end;
}				t_ants;

typedef struct s_rooms
{
	char		*name;
	int			visited;
	int			*room_links;
	int			link_count;
}				t_rooms;

typedef struct s_queue
{
	int					*que;
	int					front;
	int					rear;
	int					curr_node;
}						t_queue;

void		display_error(int i);
char		*ft_strdup_n(char *s1);
void		parse_info(t_lem *antfarm);
void		parse_rooms(t_lem *antfarm, t_rooms **rooms);
void		is_room(int i, int index, t_lem *antfarm, t_rooms **rooms);
void		count_links(char *link_names, t_rooms **rooms,
				t_lem *antfarm, int i);
void		free_2d_arr(char **arr);
int			search_room(t_rooms **rooms, char *str, int count);
t_queue		*init_queue(int size);
int			dequeue(t_queue *q);
void		enqueue(t_queue *queue, int value);
int			is_empty(t_queue *queue);
void		find_paths(t_lem *antfarm, t_rooms **rooms);
int			create_paths(t_lem *antfarm, t_rooms **rooms, t_queue *queue);
void		not_visited(t_lem *antfarm, t_rooms **rooms, t_queue *queue,
				int link);
int			get_curr_index(t_lem *antfarm, int curr_node);
int			copy_paths(t_lem *antfarm, int curr_node);
void		reset_values(t_lem *antfarm, t_rooms **rooms);
void		free_2d_int(t_lem *antfarm, int **arr);
int			find_empty_slot(int **tmp_paths, int size);
void		move_ants(t_lem *antfarm, t_rooms **rooms);
int			ft_check_end(t_lem *antfarm, t_rooms **rooms);
void		go_through_paths(t_lem *antfarm, t_ants **ants, t_rooms **rooms);
void		reset_visit_values(t_lem *antfarm, t_rooms **rooms);
int			find_index(int *arr, int size);
int			check_negative_value(char *str);
#endif