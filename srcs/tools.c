/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/13 11:39:25 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*to_lower_case(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int		is_digit(char *str)
{
	int		i;
	int		is_digit;

	i = 0;
	is_digit = 1;
	if (str && str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '.'
			&& !ft_isdigit(str[i]))
			is_digit = 0;
		i++;
	}
	return (is_digit);
}

char	*clean_line(char *str)
{
	int		index_start;
	int		index_end;

	index_start = 0;
	while (str[index_start] && (str[index_start] == ' '
		|| str[index_start] == '\t'))
		index_start++;
	index_end = ft_strlen(str) - 1;
	while (str[index_end] && (str[index_end] == ' ' || str[index_end] == '\t'))
		index_end--;
	str[index_end + 1] = '\0';
	return (str + index_start);
}

int		get_table_len(char **table)
{
	int		i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}
