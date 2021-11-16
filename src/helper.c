/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:03:30 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/16 17:34:41 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	free_2d_arr(char **arr)
{
	int		y;

	y = 0;
	while(arr[y])
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

int	ft_search_room(t_rooms **rooms, char *str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{		
		if (ft_strcmp(rooms[i]->name, str) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup_n(const char *s1)
{
	int		i;
	int		len;
	char	*des;

	len = 0;
	while (s1[len] != '\0')
		len++;
	des = (char *)malloc(sizeof(char) * (len + 2));
	if (!des)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		des[i] = s1[i];
		i++;
	}
	des[i] = '\n';
	des[i + 1] = '\0';
	return (des);
}
