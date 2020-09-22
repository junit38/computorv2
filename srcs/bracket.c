/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 17:09:15 by mery             ###   ########.fr       */
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

int 		get_split_index_2(char *value, int last_index, int end)
{
	int			i;

	i = 0;
	if (last_index <= 0)
	{
		i = end;
		while (value[i] && value[i] != '+' && value[i] != '-')
		{
			if (value[i] && (value[i] == '*' || value[i] == '/'
				|| value[i] == '%'))
				last_index = i;
			i++;
		}
		if (value[i] == '+' || value[i] == '-')
			last_index = i;
	}
	return (last_index);
}

int			get_split_index(char *value, int start, int end)
{
	int		i;
	int		last_index;

	i = start;
	last_index = -1;
	while (value[i] && value[i] != '+' && value[i] != '-')
	{
		if (value[i] && (value[i] == '*' || value[i] == '/' || value[i] == '%'))
			last_index = i;
		i--;
	}
	if (value[i] == '+' || value[i] == '-')
		last_index = i;
	last_index = get_split_index_2(value, last_index, end);
	return (last_index);
}

int			get_bracket_index(char *value)
{
	int		i;

	i = 0;
	while (value[i] && value[i] != '(')
		i++;
	if (value[i] != '(')
		return (-1);
	return (i);
}
