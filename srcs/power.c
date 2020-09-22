/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 17:04:36 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	set_power(t_param *param, char *value)
{
	char		**split;

	split = ft_strsplit(value, '^');
	if (split)
	{
		param->power = ft_atoi(split[1]);
		param->value = ft_strdup(split[0]);
		free_split(split);
	}
}

int		is_bracket_power(char *value)
{
	int			i;

	i = ft_strlen(value) - 1;
	while (value[i] && ft_isdigit(value[i]))
		i--;
	if (value[i] && value[i] == '^')
		return (1);
	return (0);
}

int		get_power(char *value)
{
	char	**split;
	int		power;

	split = ft_strsplit(value, '^');
	power = 1;
	if (split)
	{
		power = ft_atoi(split[1]);
	}
	return (power);
}

void	clean_power(char *value)
{
	int		i;

	i = 0;
	while (value[i] && value[i] != '^')
		i++;
	if (value[i] == '^')
	{
		value[i] = ' ';
		i++;
		while (value[i] && ft_isdigit(value[i]))
		{
			value[i] = ' ';
			i++;
		}
	}
}

size_t	get_power_index_last(char *value)
{
	int		index;
	size_t	i;

	index = -1;
	i = ft_strlen(value) - 1;
	while (value[i] && index == -1)
	{
		if (value[i] == '^')
			index = i;
		i--;
	}
	return (index);
}
