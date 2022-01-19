/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:49:34 by thinguye          #+#    #+#             */
/*   Updated: 2021/12/14 16:26:13 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	get_curr_index(t_lem *antfarm, int curr_node)
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

int	create_paths(t_lem *antfarm, t_rooms **rooms, t_queue *queue)
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
			if (ft_strcmp(rooms[links[i]]->name, antfarm->end) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}
