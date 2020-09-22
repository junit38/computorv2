/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/04/25 16:58:39 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

int			ft_get_term_size(t_part *part)
{
	int		i;

	i = 0;
	while (part->terms[i])
		i++;
	return (i);
}

static void	ft_set_breaks(char *part_str)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (part_str[i] != '\0')
	{
		if (j == i)
			return ;
		j = i;
		while (part_str[i] != '+' && part_str[i] != '-' && part_str[i] != '\0')
			i++;
		if (part_str[i] == '+' || part_str[i] == '-')
		{
			while (part_str[i] != ' ' && part_str[i] != '\0')
				i--;
			if (part_str[i] == ' ')
			{
				part_str[i] = '|';
				i += 2;
			}
		}
		i++;
	}
}

t_part		*ft_get_part(char *part_str)
{
	t_part	*part;
	char	**split;

	part = (t_part*)malloc(sizeof(t_part));
	if (part)
	{
		ft_set_breaks(part_str);
		split = ft_strsplit(part_str, '|');
		if (split)
			part->terms = ft_get_terms(split);
		ft_free_array(split);
	}
	return (part);
}
