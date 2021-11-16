/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:04:16 by thinguye          #+#    #+#             */
/*   Updated: 2021/11/16 17:13:03 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lem_in.h"

void	parse_info(t_lem *antfarm)
{
	char	*line;
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, ' ') && !ft_strchr(line, '-') && line[0] != '#'
			&& line[0] != 'L')
			antfarm->room_nbr++;
		
		tmp = ft_strjoin(str, line);
		free(str);
		str = ft_strdup_n(tmp);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		
	}
	antfarm->map = (char **)malloc(sizeof(char *) * antfarm->room_nbr + 1);
	antfarm->map = ft_strsplit(str, '\n');
}
