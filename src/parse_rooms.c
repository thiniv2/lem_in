/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:13:10 by thinguye          #+#    #+#             */
/*   Updated: 2021/11/11 14:46:36 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		find_index(int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == -1)
			return (i);
		i++;
	}
	return (i);
}

int		*init_int_arr(int size)
{
	int		i;
	int		*room_links;

	i = 0;
	room_links = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		room_links[i] = -1;
		i++;
	}
	return(room_links);
}

void	parse_links(t_lem *antfarm, t_rooms **rooms)
{
	int		i;
	int		room_i;
	int		room_i2;
	char	**link_names;

	i = antfarm->link_index;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
			{
				link_names = ft_strsplit(antfarm->map[i], '-');
				count_links(link_names[0], rooms, antfarm, i);
				count_links(link_names[1], rooms, antfarm, i);
				free_2d_arr(link_names);
			}
		i++;
	}
	i = 0;
	while (antfarm->room_nbr > i)
	{
		rooms[i]->room_links = init_int_arr(rooms[i]->link_count);
		i++;
	}
	i = antfarm->link_index;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ')
			&& antfarm->map[i][0] != '#')
			{
				link_names = ft_strsplit(antfarm->map[i], '-');
				room_i = ft_search_room(rooms, link_names[0], antfarm->room_nbr);
				room_i2 = ft_search_room(rooms, link_names[1], antfarm->room_nbr);
				link_names = ft_strsplit(antfarm->map[i], '-');
				rooms[room_i]->room_links[find_index(rooms[room_i]->room_links,
				rooms[room_i]->link_count)] = room_i2;
				rooms[room_i2]->room_links[find_index(rooms[room_i2]->room_links,
				rooms[room_i2]->link_count)] = room_i;
				free_2d_arr(link_names);
			}
		i++;
	}
	i = 0;
	while (rooms[i])
	{
		ft_printf("name: %s | link count: %d \n", rooms[i]->name, rooms[i]->link_count);
		ft_printf("link index:\n");
		for(int j = 0;j < rooms[i]->link_count;j++)
		{
			ft_printf("%d\n", rooms[i]->room_links[j]);
		}
		i++;
	}

}

void	parse_rooms(t_lem *antfarm, t_rooms **rooms)
{
	int	i;
	int	index;
	int	bool;

	bool = 0;
	i = 1;
	index = 0;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], ' ') && !ft_strchr(antfarm->map[i], '-')
			&& antfarm->map[i][0] != '#' && antfarm->map[i][0] != 'L')
			{
				rooms[index] = (t_rooms *)malloc(sizeof(t_rooms));
				is_room(antfarm->map[i], antfarm->map[i - 1], antfarm, rooms[index]);
				index++;
			}
		else if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' ') && antfarm->map[i][0] != '#')
			{
				if (bool == 0)
					antfarm->link_index = i;
				bool = 1;
			}
		else if (antfarm->map[i][0] != '#' && antfarm->map[i][0] != '\n')
			display_error(1);
		i++;
	}
	parse_links(antfarm, rooms);
}