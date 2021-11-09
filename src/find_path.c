/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:45:52 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/09 18:20:57 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../lem_in.h"

int	if_visited(t_lem *antfarm, char *dst)
{
	int	i;

	i = 0;
	while (i < antfarm->room_nbr)
	{
		if (ft_strcmp(antfarm->names[i][0], dst) == 0)
			if (antfarm->names[i][1][0] == '1')
				return (1);
		i++;
	}
	return (0);
}

void	visit(t_lem *antfarm, char *dst)
{
	int	i;

	i = 0;
	while (i < antfarm->room_nbr)
	{
		if (ft_strcmp(antfarm->names[i][0], dst) == 0
			&& ft_strcmp(antfarm->end, antfarm->names[i][0]) != 0)
			antfarm->names[i][1][0] = '1';
		i++;
	}	
}

void	zero_visits(t_lem *antfarm)
{
	int	i;

	i = 0;
	while(i < antfarm->room_nbr)
	{
		if (antfarm->names[i][1][0] == '1')
			antfarm->names[i][1][0] = '0';
		i++;
	}
}

void	find_possible_paths(t_links *links, char *curr_level, t_lem *antfarm)
{
	int	tmp;

	ft_printf("start_room = %s\n", curr_level);
	tmp = links->i;

	while (antfarm->i < links->link_amount)
	{
		if (links->i > 0 && links->i != tmp
			&& !ft_strcmp(antfarm->paths[links->i - 1], antfarm->end))
			break ;
		if (!ft_strcmp(curr_level, links->from_room[antfarm->i][0])
			&& ft_strcmp(links->to_room[antfarm->i][0], antfarm->start)
			&& if_visited(antfarm, links->to_room[antfarm->i][0]) == 0)
		{
			visit(antfarm, links->to_room[antfarm->i][0]);
			antfarm->paths[links->i] = links->to_room[antfarm->i][0];
		//	ft_printf("next room = %s\n", links->to_room[antfarm->i][0]);
			links->i++;
			break ;
		}
		else if (!ft_strcmp(curr_level, links->to_room[antfarm->i][0])
			&& ft_strcmp(links->from_room[antfarm->i][0], antfarm->start)
			&& if_visited(antfarm, links->from_room[antfarm->i][0]) == 0)
		{
			visit(antfarm, links->from_room[antfarm->i][0]);
			antfarm->paths[links->i] = links->from_room[antfarm->i][0];
		//	ft_printf("next room = %s\n", links->from_room[antfarm->i][0]);
			links->i++;
			break ;
		}
		antfarm->i++;
		
	}
	if (ft_strcmp(antfarm->paths[links->i - 1], antfarm->end) != 0 && tmp != links->i)
	{
		antfarm->i = 0;
		find_possible_paths(links, antfarm->paths[links->i - 1], antfarm);
	}
}

void	find_paths(t_lem *antfarm, t_links *links)
{
	int		i;
	int		x;
	char	***curr_level;

	i = 0;
	x = 0;
	curr_level = (char ***)malloc(sizeof(char **) * links->link_amount + 1);
	while (links->link_amount > i)
	{
		if (!ft_strcmp(antfarm->start, links->from_room[i][0]))
		{
			curr_level[x] = (char **)malloc(sizeof(char *) * 2);
			curr_level[x][0] = ft_strdup(links->to_room[i][0]);
			curr_level[x][1] = ft_strdup("0");
			x++;
		}
		else if (!ft_strcmp(antfarm->start, links->to_room[i][0]))
		{
			curr_level[x] = (char **)malloc(sizeof(char *) * 2);
			curr_level[x][0] = ft_strdup(links->from_room[i][0]);
			curr_level[x][1] = ft_strdup("0");
			x++;
		}
		i++;
	}
	curr_level[x] = NULL;
	x = 0;
	links->i = 0;
	while (curr_level[x])
	{
		i = -1;
		antfarm->i = 0;
		find_possible_paths(links, curr_level[x][0], antfarm);
		x++;
	}
}
*/