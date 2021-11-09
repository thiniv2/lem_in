/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:41 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/09 18:24:18 by thinguye         ###   ########.fr       */
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
	char		**paths;
	int			room_nbr;
	int			i;
	char		**next_level;
	
	int			link_index;
}				t_lem;

typedef struct s_links
{
	int			link_amount;
	int			i;
	char		***from_room;
	char		***to_room;
}				t_links;

typedef struct	s_rooms
{
	char		*name;
	int			visited;
	int			*room_links;
	int			link_count;
}				t_rooms;

void		display_error(int i);
//void		is_room(char *line, char *prev_line, t_lem *antfarm);
//void		is_link(char *line, t_lem *antfarm, t_links *links);
//int			ft_str_search(char ***names, char *str, int count);
//int			parse_info(t_lem *antfarm, t_links *links);
char		*ft_strdup_n(const char *s1);
void		find_paths(t_lem *antfarm, t_links *links);
int		parse_info(t_lem *antfarm, t_links *links);


void	is_room(char *line, char *prev_line, t_lem *antfarm, t_rooms *rooms);
void	parse_rooms(t_lem *antfarm, t_rooms **rooms);
void	count_links(char *link_names, t_rooms **rooms, t_lem *antfarm, int i);
void	free_2d_arr(char **arr);
int		ft_search_room(t_rooms **rooms, char *str, int count);
#endif