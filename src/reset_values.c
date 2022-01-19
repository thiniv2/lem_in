/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:54:19 by thinguye          #+#    #+#             */
/*   Updated: 2021/12/14 14:14:45 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static	int	check_saved(int i, t_lem *antfarm)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < antfarm->y)
	{
		while (x < antfarm->room_nbr)
		{
			if (antfarm->paths[y][x] == INT_MAX)
				break ;
			if (i == antfarm->paths[y][x])
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	reset_values(t_lem *antfarm, t_rooms **rooms)
{
	int	i;

	i = 0;
	while (i < antfarm->room_nbr)
	{
		if ((rooms[i]->visited == 1 && check_saved(i, antfarm) == 0)
			|| ft_strcmp(rooms[i]->name, antfarm->end) == 0)
		{
			rooms[i]->visited = 0;
		}
		i++;
	}
}
