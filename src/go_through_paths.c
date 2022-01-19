/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_through_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:02:22 by thinguye          #+#    #+#             */
/*   Updated: 2021/12/16 19:42:36 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	find_next_room(t_lem *antfarm, int curr_room, int path_index)
{
	int	i;

	i = 0;
	while (antfarm->paths[path_index][i] != INT_MAX)
	{
		if (antfarm->paths[path_index][i] == curr_room)
			return (antfarm->paths[path_index][i + 1]);
		i++;
	}
	return (0);
}

int	check_is_end(t_ants **ants, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ants[i]->is_end)
			return (1);
		i++;
	}
	return (0);
}

int	print_move(int i, int count, t_ants **ants, t_rooms **rooms)
{
	if (count == 0)
	{
		ft_printf("L%d-%s", ants[i]->ant_nbr,
			rooms[ants[i]->curr_room]->name);
		count = 1;
	}
	else
		ft_printf(" L%d-%s", ants[i]->ant_nbr,
			rooms[ants[i]->curr_room]->name);
	return (count);
}

static	void	free_ants(t_ants **ants, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(ants[i]);
		i++;
	}
	free(ants);
}

void	go_through_paths(t_lem *antfarm, t_ants **ants, t_rooms **rooms)
{
	int	i;
	int	count;

	while (check_is_end(ants, antfarm->n_ants))
	{
		i = -1;
		count = 0;
		while (++i < antfarm->n_ants)
		{
			if (rooms[ants[i]->curr_room]->visited < 2 && ants[i]->is_end == 0)
			{
				count = print_move(i, count, ants, rooms);
				if (ants[i]->curr_room == antfarm->end_index)
					ants[i]->is_end = 1;
				else
					rooms[ants[i]->curr_room]->visited = 2;
				if (ants[i]->is_end == 0)
					ants[i]->curr_room = find_next_room(antfarm,
							ants[i]->curr_room, ants[i]->path_index);
			}
		}
		ft_printf("\n");
		reset_visit_values(antfarm, rooms);
	}
	free_ants(ants, antfarm->n_ants);
}
