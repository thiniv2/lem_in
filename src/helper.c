/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:03:30 by epalomak          #+#    #+#             */
/*   Updated: 2022/01/21 13:00:32 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	find_index(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == -1)
			return (i);
		i++;
	}
	return (i);
}

int	find_empty_slot(int **tmp_paths, int size)
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

int	ft_check_end(t_lem *antfarm, t_rooms **rooms)
{
	int	i;

	i = 0;
	while (antfarm->tmp_paths[antfarm->i][i] != -1)
	{
		if (ft_strcmp(rooms[antfarm->tmp_paths[antfarm->i][i]]->name,
			antfarm->end) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	search_room(t_rooms **rooms, char *str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strcmp(rooms[i]->name, str) == 0)
			return (i);
		i++;
	}
	return (INT_MAX);
}

char	*ft_strdup_n(char *s1)
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
