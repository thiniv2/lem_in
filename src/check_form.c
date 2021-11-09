/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:35:20 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/09 18:37:59 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	count_links(char *link_names, t_rooms **rooms, t_lem *antfarm, int i)
{
	int		link_index;
	char	**arr;
	
	link_index = ft_search_room(rooms, link_names, antfarm->room_nbr);
	if (rooms[link_index]->link_count != 0)
		return ;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
			{
				arr = ft_strsplit(antfarm->map[i], '-');
				if(ft_strcmp(arr[0], link_names) == 0|| ft_strcmp(arr[1], link_names) == 0)
				{
					rooms[link_index]->link_count++;
				}
				free_2d_arr(arr);
			}
		i++;
	}
}

/*
void	is_link(char *line, t_lem *antfarm, t_links *links)
{
	char	**room;

	room = ft_strsplit(line, '-');
	if (ft_str_search(antfarm->names, room[0], antfarm->room_nbr) == 1)
		display_error(3);
	if (ft_str_search(antfarm->names, room[1], antfarm->room_nbr) == 1)
		display_error(3);
	links->from_room[links->i][0] = ft_strdup(room[0]);
	links->to_room[links->i][0] = ft_strdup(room[1]);
	links->from_room[links->i][1] = ft_strdup("0");
	links->to_room[links->i][1] = ft_strdup("0");
	links->i++;
	free(room);
}
*/
void	is_room(char *line, char *prev_line, t_lem *antfarm, t_rooms *rooms)
{
	char	**name;

	name = ft_strsplit(line, ' ');
	if (ft_strcmp(prev_line, "##start") == 0 && !antfarm->start)
	{
		antfarm->start = ft_strdup(name[0]);
	}
	else if (ft_strcmp(prev_line, "##end") == 0 && !antfarm->end)
	{
		antfarm->end = ft_strdup(name[0]);
	}
	rooms->name = ft_strdup(name[0]);
	rooms->visited = 0;
	rooms->link_count = 0;
	free(name);
}

/*
void	is_room(char *line, char *prev_line, t_lem *antfarm)
{
	char	**name;

	name = ft_strsplit(line, ' ');
	if (ft_strcmp(prev_line, "##start") == 0 && !antfarm->start)
	{
		antfarm->start = ft_strdup(name[0]);
	}
	else if (ft_strcmp(prev_line, "##end") == 0 && !antfarm->end)
	{
		antfarm->end = ft_strdup(name[0]);
	}
	antfarm->names[antfarm->i][1] = ft_strdup("0");
	antfarm->names[antfarm->i++][0] = ft_strdup(name[0]);
	free(name);
}
*/