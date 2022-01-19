/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:16:25 by thinguye          #+#    #+#             */
/*   Updated: 2021/12/16 20:02:44 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** add error check if duplicate links/rooms
*/
void	display_error(int i)
{
	if (i == 1)
		ft_printf("Error : Invalid antfarm\n");
	if (i == 2)
		ft_printf("Error : Invalid room\n");
	if (i == 3)
		ft_printf("Error : Link has a invalid room name\n");
	if (i == 4)
		ft_printf("Error : Duplicate room name \n");
	exit(0);
}

void	set_struct(t_lem *antfarm)
{
	antfarm->n_ants = 0;
	antfarm->room_nbr = 0;
	antfarm->i = 0;
	antfarm->y = 0;
	antfarm->link_index = 0;
	antfarm->tmp_paths = 0;
	antfarm->paths = 0;
	antfarm->end_index = 0;
	antfarm->boole = 0;
}

void	free_paths(t_lem *antfarm, int **arr)
{
	int		i;

	i = 0;
	while (i < antfarm->y)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(void)
{
	t_lem	*antfarm;
	t_rooms	**rooms;
	int		i;

	i = -1;
	antfarm = (t_lem *)malloc(sizeof(t_lem) * 1);
	set_struct(antfarm);
	parse_info(antfarm);
	rooms = (t_rooms **)malloc(sizeof(t_rooms) * antfarm->room_nbr);
	parse_rooms(antfarm, rooms);
	find_paths(antfarm, rooms);
	move_ants(antfarm, rooms);
	free_paths(antfarm, antfarm->paths);
	free(antfarm->start);
	free(antfarm->end);
	free(antfarm);
	while (rooms[++i])
	{
		free(rooms[i]->name);
		free(rooms[i]->room_links);
		free(rooms[i]);
	}
	free(rooms);
	return (0);
}
