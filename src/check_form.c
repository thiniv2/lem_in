/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:35:20 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/11 16:34:31 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	count_links(char *name, t_rooms **rooms, t_lem *antfarm, int i)
{
	int		link_index;
	char	**arr;
	
	link_index = ft_search_room(rooms, name, antfarm->room_nbr);
	if (rooms[link_index]->link_count != 0)
		return ;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
			{
				arr = ft_strsplit(antfarm->map[i], '-');
				if(ft_strcmp(arr[0], name) == 0|| ft_strcmp(arr[1], name) == 0)
					rooms[link_index]->link_count++;
				free_2d_arr(arr);
			}
		i++;
	}
}

void	is_room(char *line, char *prev_line, t_lem *antfarm, t_rooms *rooms)
{
	char	**name;

	name = ft_strsplit(line, ' ');
	if (ft_strcmp(prev_line, "##start") == 0)
		antfarm->start = ft_strdup(name[0]);
	else if (ft_strcmp(prev_line, "##end") == 0)
		antfarm->end = ft_strdup(name[0]);
	rooms->name = ft_strdup(name[0]);
	rooms->visited = 0;
	rooms->link_count = 0;
	free(name);
}
