/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:03:30 by epalomak          #+#    #+#             */
/*   Updated: 2021/11/09 19:09:10 by thinguye         ###   ########.fr       */
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

/*
int	ft_str_search(char ***names, char *str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strcmp(names[i][0], str) == 0)
			return (0);
		i++;
	}
	return (1);
}
*/
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
