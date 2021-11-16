/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:04:17 by thinguye          #+#    #+#             */
/*   Updated: 2021/11/16 17:38:58 by thinguye         ###   ########.fr       */
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

int	copy_paths(t_lem *antfarm, int curr_node)
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

void	save_path(t_lem *antfarm, t_rooms **rooms)
{
	int		x;

	x = 0;
	if (!antfarm->paths)
		antfarm->paths = (int **)malloc(sizeof(int *) * antfarm->room_nbr);
	antfarm->paths[antfarm->y] = (int *)malloc(sizeof(int) * antfarm->room_nbr);
	ft_printf("paths:\n");
	while (antfarm->tmp_paths[antfarm->i][x] != -1)
	{
		antfarm->paths[antfarm->y][x] = antfarm->tmp_paths[antfarm->i][x];
		ft_printf("%s-", rooms[antfarm->paths[antfarm->y][x]]->name);
		x++;
	}
	ft_printf("\n");
}

void	find_paths(t_lem *antfarm, t_rooms **rooms)
{
	t_queue	*queue;
	int		start_index;

	start_index = ft_search_room(rooms, antfarm->start, antfarm->room_nbr);
	queue = init_queue(antfarm->room_nbr);
	init_array(antfarm, start_index);
	rooms[start_index]->visited = 1;
	enqueue(queue, start_index);
	while (!is_empty(queue))
	{
		queue->curr_node = dequeue(queue);
		if (create_paths(antfarm, rooms, queue) == 1)
			break ;
	}
	save_path(antfarm, rooms);
	antfarm->y += 1;
	free_2d_int(antfarm, antfarm->tmp_paths);
	reset_values(antfarm, rooms);
	if (antfarm->y < rooms[antfarm->end_index]->link_count)
		find_paths(antfarm, rooms);
}
