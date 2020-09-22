/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:39:02 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

char 		*get_clean_line(char *line)
{
	int 	i;
	char 	*clean;
	char 	*tmp;

	i = 0;
	clean = (char*)malloc(sizeof(*clean) * ft_strlen(line) + 2);
	clean = ft_strcpy(clean, line);
	tmp = clean;
	while (line[i])
	{
		if (line[i + 1] && ft_isdigit(line[i]) && ft_isalpha(line[i + 1]))
		{
			tmp = clean;
			clean = (char*)malloc(sizeof(*clean) * ft_strlen(line) + 2);
			clean = ft_strncpy(clean, line, i + 1);
			clean = ft_strcat(clean, "*");
			clean = ft_strcat(clean, line + i + 1);
			line = clean;
			if (tmp)
				free(tmp);
		}
		i++;
	}
	return (clean);
}

char 		*get_clean_line_2(char *line)
{
	size_t 	i;
	char 	*clean;
	char 	*tmp;

	i = 0;
	clean = (char*)malloc(sizeof(*clean) * ft_strlen(line) + 2);
	clean = ft_strcpy(clean, line);
	tmp = clean;
	while (line[i] && i < ft_strlen(line))
	{
		if (line[i] == '-')
		{
			tmp = clean;
			clean = (char*)malloc(sizeof(*clean) * ft_strlen(line) + 5);
			clean = ft_strncpy(clean, line, i + 1);
			clean = ft_strcat(clean, "0 - ");
			clean = ft_strcat(clean, line + i + 1);
			line = clean;
			i = i + 5;
			if (tmp)
				free(tmp);
		}
		i++;
	}
	return (clean);
}
