/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:27:19 by thinguye          #+#    #+#             */
/*   Updated: 2021/12/14 17:47:23 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	free_2d_arr(char **arr)
{
	int		y;

	y = 0;
	while (arr[y])
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

void	free_2d_int(t_lem *antfarm, int **arr)
{
	int		i;

	i = 0;
	while (i < antfarm->room_nbr)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
