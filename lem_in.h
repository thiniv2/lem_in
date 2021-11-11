/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:41 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/11 15:40:12 by thinguye         ###   ########.fr       */
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
	char		***names;
	char		**map;
	int			room_nbr;
	int			i;
	char		**next_level;
	int			link_index;
	int			**tmp_paths;
}				t_lem;

typedef struct s_links
{
	int			link_amount;
	int			i;
}				t_links;

typedef struct	s_rooms
{
	char		*name;
	int			visited;
	int			*room_links;
	int			link_count;
}				t_rooms;

typedef struct			s_queue
{
	int					*que;
	int					front;
	int					rear;
	int					curr_node;
}						t_queue;

void		display_error(int i);
char		*ft_strdup_n(const char *s1);
void		parse_info(t_lem *antfarm, t_links *links);
void		parse_rooms(t_lem *antfarm, t_rooms **rooms);
void		is_room(char *line, char *prev_line, t_lem *antfarm, t_rooms *rooms);
void		count_links(char *link_names, t_rooms **rooms, t_lem *antfarm, int i);
void		free_2d_arr(char **arr);
int			ft_search_room(t_rooms **rooms, char *str, int count);
t_queue		*init_queue(int size);
int			dequeue(t_queue *q);
void		enqueue(t_queue *queue, int value);
int			is_empty(t_queue *queue);
void		find_paths(t_lem *antfarm, t_rooms **rooms);
#endif