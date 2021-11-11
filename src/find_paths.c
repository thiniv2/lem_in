/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:04:17 by thinguye          #+#    #+#             */
/*   Updated: 2021/11/11 16:54:46 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	init_new_path(t_lem *antfarm, int y, int res)
{
	int	x;
	
	x = 0;
	while (x < antfarm->room_nbr)
	{
		if (antfarm->tmp_paths[y][x + 1] != -1)
			antfarm->tmp_paths[res][x] = antfarm->tmp_paths[y][x];
		else
			break ;
		x++;
	}
	return (res);
}

int		find_empty_slot(int **tmp_paths, int size)
{
	int		y;

	y = 0;
	while (y < size)
	{
		if (tmp_paths[y][1] == -1)
			return (y);
		y++;
	}
	return (0);
}

int		copy_paths(t_lem *antfarm, int curr_node)
{
	int		y;
	int		x;
	int		res;
	
	y = 0;
	x = 0;
	res = 0;
	while (y < antfarm->room_nbr)
	{
		x = 0;
		while (x < antfarm->room_nbr)
		{
			if (antfarm->tmp_paths[y][x] == curr_node)
			{
				res = find_empty_slot(antfarm->tmp_paths, antfarm->room_nbr);
				return (init_new_path(antfarm, y, res));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		get_curr_index(t_lem *antfarm, int curr_node)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < antfarm->room_nbr)
	{
		x = 0;
		while (x < antfarm->room_nbr)
		{
			if (antfarm->tmp_paths[y][x] == curr_node
				&& antfarm->tmp_paths[y][x + 1] == -1)
				return (y);
			if (antfarm->tmp_paths[y][x] == -1)
				break ;
			x++;
		}
		y++;
	}
	return (copy_paths(antfarm, curr_node));
}

void	not_visited(t_lem *antfarm, t_rooms **rooms, t_queue *queue, int link)
{
	int		i;
	
	i = 0;
	antfarm->i = get_curr_index(antfarm, queue->curr_node);
	while (i < antfarm->room_nbr)
	{
		if (antfarm->tmp_paths[antfarm->i][i] == -1)
		{
			antfarm->tmp_paths[antfarm->i][i] = link;
			rooms[link]->visited = 1;
			enqueue(queue, link);
			return ;
		}
		i++;
	}
}

int		create_paths(t_lem *antfarm, t_rooms **rooms, t_queue *queue)
{
	int		*links;
	int		i;
	
	i = 0;
	links = rooms[queue->curr_node]->room_links;
	while (i < rooms[queue->curr_node]->link_count)
	{
		if (rooms[links[i]]->visited == 0)
		{
			not_visited(antfarm, rooms, queue, links[i]);
			ft_printf("curr: %d | LINK: %d\n", queue->curr_node, links[i]);
		}
		i++;
	}
	return (0);
}

void	init_array(t_lem *antfarm, int start_index)
{
	int		y;
	int		x;

	y = 0;
	antfarm->tmp_paths = (int **)malloc(sizeof(int *) * antfarm->room_nbr);
	while (y < antfarm->room_nbr)
	{
		x = 0;
		antfarm->tmp_paths[y] = (int *)malloc(sizeof(int) * antfarm->room_nbr);
		while (x <= antfarm->room_nbr)
		{
			if (x == 0)
				antfarm->tmp_paths[y][x] = start_index;
			else
				antfarm->tmp_paths[y][x] = -1;
			x++;
		}
		y++;
	}
}

void	find_paths(t_lem *antfarm, t_rooms **rooms)
{
	t_queue *queue;
	int		start_index;

	ft_printf("start: %s\n", antfarm->start);
	start_index = ft_search_room(rooms, antfarm->start, antfarm->room_nbr);
	queue = init_queue(antfarm->room_nbr);
	init_array(antfarm, start_index);
	rooms[start_index]->visited = 1;
	enqueue(queue, start_index);
	while (!is_empty(queue))
	{
		queue->curr_node = dequeue(queue);
		create_paths(antfarm, rooms, queue);
		ft_printf("END\n");
	}
	// save_path()
	// free(tmp_paths)
	//run find paths again until no new paths are found

	/*
	TODO: save path if end found
	then reset visit values of everything else than the saved path
	*/


	int i = 0;
	int	x = 0;
	while (i < antfarm->room_nbr)
	{
		x = 0;
		while (x < antfarm->room_nbr)
		{
			if (antfarm->tmp_paths[i][x] == -1)
				break ;
			ft_printf("%s-", rooms[antfarm->tmp_paths[i][x]]->name);
			x++;
		}
		ft_printf("\n");
		i++;
	}

	
}