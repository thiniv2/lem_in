/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:41 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/16 17:40:31 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>

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
}				t_lem;

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
char		*ft_strdup_n(const char *s1);
void		parse_info(t_lem *antfarm);
void		parse_rooms(t_lem *antfarm, t_rooms **rooms);
void		is_room(int i, int index, t_lem *antfarm, t_rooms *rooms);
void		count_links(char *link_names, t_rooms **rooms,
				t_lem *antfarm, int i);
void		free_2d_arr(char **arr);
int			ft_search_room(t_rooms **rooms, char *str, int count);
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
#endif