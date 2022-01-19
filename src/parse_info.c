/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:04:16 by thinguye          #+#    #+#             */
/*   Updated: 2022/01/18 12:49:06 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	check_errors(t_lem *antfarm)
{
	if (antfarm->n_ants <= 0 || antfarm->room_nbr <= 0
		|| antfarm->n_ants >= INT_MAX || antfarm->boole == -1)
		display_error(1);
}

void	parse_info(t_lem *antfarm)
{
	char	*line;
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	while (get_next_line(0, &line))
	{
		if (line[0] != '#' && !antfarm->n_ants)
			antfarm->n_ants = ft_atoi(line);
		if (ft_strchr(line, ' ') && !ft_strchr(line, '-')
			&& line[0] != '#' && line[0] != 'L')
			antfarm->room_nbr++;
		if (line[0] == '\0')
			antfarm->boole = -1;
		tmp = ft_strjoin(str, line);
		free(str);
		str = ft_strdup_n(tmp);
		free(line);
		free(tmp);
	}
	write(1, str, ft_strlen(str));
	check_errors(antfarm);
	antfarm->map = ft_strsplit(str, '\n');
	free(str);
}
