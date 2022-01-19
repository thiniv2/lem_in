/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:49:31 by thinguye          #+#    #+#             */
/*   Updated: 2022/01/19 14:58:29 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	check_negative_value(char *str)
{
	char	**arr;
	int		ret1;
	int		ret2;

	arr = ft_strsplit(str, ' ');
	ret1 = ft_atoi(arr[1]);
	ret2 = ft_atoi(arr[2]);
	if (ret1 < 0 || ret2 < 0)
	{
		free_2d_arr(arr);
		return (1);
	}
	free_2d_arr(arr);
	return (0);
}
