/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:13:10 by thinguye          #+#    #+#             */
/*   Updated: 2022/01/19 14:57:33 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	*init_int_arr(int size)
{
	int	i;
	int	*room_links;

	i = 0;
	room_links = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		room_links[i] = -1;
		i++;
	}
	return (room_links);
}

void	set_room_index(t_lem *antfarm, t_rooms **rooms, char **names)
{
	int		room_i;
	int		room_i2;
	int		i;

	i = antfarm->link_index;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
		{
			names = ft_strsplit(antfarm->map[i], '-');
			room_i = search_room(rooms, names[0], antfarm->room_nbr);
			room_i2 = search_room(rooms, names[1], antfarm->room_nbr);
			rooms[room_i]->room_links[find_index(rooms[room_i]->room_links,
					rooms[room_i]->link_count)] = room_i2;
			rooms[room_i2]->room_links[find_index(rooms[room_i2]->room_links,
					rooms[room_i2]->link_count)] = room_i;
			free_2d_arr(names);
		}
		i++;
	}
}

void	parse_links(t_lem *antfarm, t_rooms **rooms)
{
	int		i;
	char	**names;

	i = antfarm->link_index;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
		{
			names = ft_strsplit(antfarm->map[i], '-');
			if (search_room(rooms, names[0], antfarm->room_nbr) == INT_MAX
				|| search_room(rooms, names[1], antfarm->room_nbr) == INT_MAX)
				display_error(3);
			count_links(names[0], rooms, antfarm, i);
			count_links(names[1], rooms, antfarm, i);
			free_2d_arr(names);
		}
		i++;
	}
	i = -1;
	while (antfarm->room_nbr > ++i)
		rooms[i]->room_links = init_int_arr(rooms[i]->link_count);
	set_room_index(antfarm, rooms, names);
	free_2d_arr(antfarm->map);
}

void	check_index(int index)
{
	if (index == 0)
		display_error(1);
}

void	parse_rooms(t_lem *antfarm, t_rooms **rooms)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (antfarm->map[++i])
	{
		if (ft_strchr(antfarm->map[i], ' ') && !ft_strchr(antfarm->map[i], '-')
			&& antfarm->map[i][0] != '#' && antfarm->map[i][0] != 'L')
		{
			rooms[index] = (t_rooms *)malloc(sizeof(t_rooms));
			is_room(i, index, antfarm, rooms);
			index++;
		}
		else if (ft_strchr(antfarm->map[i], '-')
			&& !(ft_strchr(antfarm->map[i], ' ')) && antfarm->map[i][0] != '#')
		{
			if (antfarm->link_index == 0)
				antfarm->link_index = i;
		}
		else if (antfarm->map[i][0] != '#')
			if (check_negative_value(antfarm->map[i]) == 0)
				display_error(1);
	}
	check_index(antfarm->link_index);
	parse_links(antfarm, rooms);
}
