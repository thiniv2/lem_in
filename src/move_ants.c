/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:42:37 by epalomak          #+#    #+#             */
/*   Updated: 2022/01/18 12:49:10 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	path_len(t_lem *antfarm, int i)
{
	int	len;

	len = 0;
	while (antfarm->paths[i][len] != INT_MAX)
		len++;
	return (len - 2);
}

int	shortest_path(t_paths **path, int size)
{
	int	len;
	int	result;
	int	i;

	i = 0;
	len = INT_MAX;
	while (i < size)
	{
		if (path[i]->path_len + path[i]->ants < len)
		{
			len = path[i]->path_len + path[i]->ants;
			result = i;
		}
		i++;
	}
	return (result);
}

void	reset_visit_values(t_lem *antfarm, t_rooms **rooms)
{
	int	i;
	int	x;

	i = 0;
	while (i < antfarm->y)
	{
		x = 0;
		while (antfarm->paths[i][x] != INT_MAX)
		{
			rooms[antfarm->paths[i][x]]->visited = 1;
			x++;
		}
		i++;
	}
}

void	init_ants(t_lem *antfarm, t_paths **paths, t_rooms **rooms)
{
	int		i;
	int		j;
	t_ants	**ants;

	ants = (t_ants **)malloc(sizeof(t_ants *) * antfarm->n_ants);
	i = 0;
	j = 0;
	while (antfarm->n_ants > i)
	{
		ants[i] = (t_ants *)malloc(sizeof(t_ants));
		ants[i]->ant_nbr = i + 1;
		ants[i]->is_end = 0;
		if (antfarm->y == j || paths[j]->ants == 0)
			j = 0;
		ants[i]->curr_room = paths[j]->start_room;
		ants[i]->path_index = j;
		paths[j]->ants -= 1;
		j++;
		i++;
	}
	i = -1;
	while (++i < antfarm->y)
		free(paths[i]);
	go_through_paths(antfarm, ants, rooms);
	free(paths);
}

void	move_ants(t_lem *antfarm, t_rooms **rooms)
{
	t_paths	**paths;
	int		i;
	int		index;

	i = 0;
	if (antfarm->y == 0)
		display_error(1);
	paths = (t_paths **)malloc(sizeof(t_paths *) * antfarm->y);
	while (i < antfarm->y)
	{
		paths[i] = (t_paths *)malloc(sizeof(t_paths));
		paths[i]->ants = 0;
		paths[i]->start_room = antfarm->paths[i][1];
		paths[i]->path_len = path_len(antfarm, i);
		i++;
	}
	i = 0;
	index = 0;
	while (i < antfarm->n_ants)
	{
		index = shortest_path(paths, antfarm->y);
		paths[index]->ants += 1;
		i++;
	}
	init_ants(antfarm, paths, rooms);
}
