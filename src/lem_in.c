  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:35:14 by epalomak          #+#    #+#             */
/*   Updated: 2021/10/20 17:06:54 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	display_error(int i)
{
	if (i == 1)
		ft_printf("Error : Invalid antfarm\n");
	if (i == 2)
		ft_printf("Error : Invalid room\n");
	if (i == 3)
		ft_printf("Error : Link has a invalid room name\n");
	if (i == 4)
		ft_printf("Error : \n");
	// add error if duplicate links/rooms
	exit(0);
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
				rooms[room_i]->room_links[find_index(rooms[room_i]->room_links, rooms[room_i]->link_count)] = room_i2;
				rooms[room_i2]->room_links[find_index(rooms[room_i2]->room_links, rooms[room_i2]->link_count)] = room_i;
				free_2d_arr(link_names);
			}
		i++;
	}
	i = 0;
	while (rooms[i])
	{
		ft_printf("name: %s | link count %d \n", rooms[i]->name, rooms[i]->link_count);
		ft_printf("links\n");
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

/*
static	void	read_input(t_lem *antfarm, t_links *links)
{
	int	i;

	i = 1;
	while (antfarm->map[i])
	{
		if (ft_strchr(antfarm->map[i], ' ') && !ft_strchr(antfarm->map[i], '-')
			&& antfarm->map[i][0] != '#' && antfarm->map[i][0] != 'L')
			is_room(antfarm->map[i], antfarm->map[i - 1], antfarm);
		else if (ft_strchr(antfarm->map[i], '-')
			&& !ft_strchr(antfarm->map[i], ' '))
			is_link(antfarm->map[i], antfarm, links);
		else if (antfarm->map[i][0] != '#' && antfarm->map[i][0] != '\n')
		{
			free(antfarm->map[i]);
			display_error(1);
		}
		i++;
	}
}
*/
static	void	set_struct(t_lem *antfarm, t_links *links)
{
	int i;

	i= 0;
	antfarm->start = NULL;
	antfarm->end = NULL;
	antfarm->i = 0;
	antfarm->names = (char ***)malloc(sizeof(char **) * antfarm->room_nbr);
	antfarm->paths = (char **)malloc(sizeof(char *) * links->link_amount + 1);
	links->from_room = (char ***)malloc(sizeof(char **) * links->link_amount + 1);
	links->to_room = (char ***)malloc(sizeof(char **) * links->link_amount + 1);
	while (i < antfarm->room_nbr)
	{
		antfarm->names[i] = (char **)malloc(sizeof(char *) * 2);
		i++;
	}
	i = 0;
	while (i < links->link_amount)
	{
		links->to_room[i] = (char **)malloc(sizeof(char *) * 2);
		links->from_room[i] = (char **)malloc(sizeof(char *) * 2);
		i++;
	}
	links->i = 0;
	if (!antfarm->names | !links->from_room | !links->to_room)
		exit(-1);
}

int	main(void)
{
	t_lem	*antfarm;
	t_links	*links;
	t_rooms	**rooms;

	links = (t_links *)malloc(sizeof(t_links));
	antfarm = (t_lem *)malloc(sizeof(t_lem));
	if (parse_info(antfarm, links) == 0)
		return (0);
	rooms = (t_rooms **)malloc(sizeof(t_rooms) * antfarm->room_nbr);
	set_struct(antfarm, links);
//	read_input(antfarm, links);
	parse_rooms(antfarm, rooms);
//	find_paths(antfarm, links);
	return (0);
}
