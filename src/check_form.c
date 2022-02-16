/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:35:20 by epalomak          #+#    #+#             */
/*   Updated: 2022/01/21 13:36:51 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	count_links(char *name, t_rooms **rooms, t_lem *antfarm, int i)
{
	int		link_index;
	char	**arr;

	link_index = search_room(rooms, name, antfarm->room_nbr);
	if (rooms[link_index]->link_count != 0)
		return ;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
		{
			arr = ft_strsplit(antfarm->map[i], '-');
			if (!arr[0] || !arr[1])
				display_error(1);
			if (ft_strcmp(arr[0], name) == 0 || ft_strcmp(arr[1], name) == 0)
				rooms[link_index]->link_count++;
			free_2d_arr(arr);
		}
		i++;
	}
}

void	is_room(int i, int index, t_lem *antfarm, t_rooms **rooms)
{
	char	**name;

	name = ft_strsplit(antfarm->map[i], ' ');
	if (ft_strchr(name[0], '-'))
		display_error(1);
	if (ft_strcmp(antfarm->map[i - 1], "##start") == 0)
		antfarm->start = ft_strdup(name[0]);
	else if (ft_strcmp(antfarm->map[i - 1], "##end") == 0)
	{
		antfarm->end_index = index;
		antfarm->end = ft_strdup(name[0]);
	}
	if (search_room(rooms, name[0], index) != INT_MAX)
		display_error(1);
	rooms[index]->name = ft_strdup(name[0]);
	rooms[index]->visited = 0;
	rooms[index]->link_count = 0;
	free_2d_arr(name);
}
