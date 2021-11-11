/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:16:25 by thinguye          #+#    #+#             */
/*   Updated: 2021/11/11 15:03:40 by thinguye         ###   ########.fr       */
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
		ft_printf("Error : \n");
	exit(0);
}

int	main(void)
{
	t_lem	*antfarm;
	t_links	*links;
	t_rooms	**rooms;

	links = (t_links *)malloc(sizeof(t_links));
	antfarm = (t_lem *)malloc(sizeof(t_lem));
	parse_info(antfarm, links);
	rooms = (t_rooms **)malloc(sizeof(t_rooms) * antfarm->room_nbr);
	parse_rooms(antfarm, rooms);
	find_paths(antfarm, rooms);
	return (0);
}
