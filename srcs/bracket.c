/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/01 13:31:52 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int			get_bracket_index_start(char *value)
{
	int		i;

	i = 0;
	while (value[i] && value[i] != '(')
		i++;
	if (value[i] && value[i] == '(')
		return (i);
	return (-1);
}

int			get_bracket_index_end(char *value)
{
	int		i;
	int		index_end;
	int		opened;

	i = 0;
	opened = 0;
	index_end = -1;
	while (value[i] && index_end == -1)
	{
		if (value[i] == '(')
			opened++;
		if (value[i] == ')')
		{
			opened--;
			if (opened == 0)
				index_end = i;
		}
		i++;
	}
	return (index_end);
}

static int	is_in_bracket(char *value, int i)
{
	int		j;
	int		opened;

	j = 0;
	opened = 0;
	while (value[j])
	{
		if (value[j] == '(')
			opened++;
		else if (value[j] == ')')
			opened--;
		if (j == i && opened)
			return (1);
		j++;
	}
	return (0);
}

static int	get_split_index_2(char *value)
{
	int		i;
	int		split_index;

	i = 0;
	split_index = -1;
	while (value[i] && split_index == -1)
	{
		if (!is_in_bracket(value, i) && value[i] == '%')
			split_index = i;
		i++;
	}
	return (split_index);
}

int			get_split_index(char *value)
{
	int		i;
	int		split_index;

	i = 0;
	split_index = -1;
	while (value[i] && split_index == -1)
	{
		if (!is_in_bracket(value, i) && (value[i] == '+' || value[i] == '-'))
			split_index = i;
		i++;
	}
	if (split_index == -1)
	{
		i = 0;
		while (value[i] && split_index == -1)
		{
			if (!is_in_bracket(value, i) && (value[i] == '*'
				|| value[i] == '/'))
				split_index = i;
			i++;
		}
	}
	if (split_index == -1)
		split_index = get_split_index_2(value);
	return (split_index);
}
