/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/28 15:03:51 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

char		**exp_split(char *exp, int c)
{
	int		index;
	char	**split;

	index = 0;
	split = (char**)malloc(sizeof(split) * 3);
	while (exp[index] != c)
		index++;
	split[0] = ft_strndup(exp, index);
	split[1] = ft_strdup(exp + index + 1);
	split[2] = NULL;
	return (split);
}

char		**exp_split_str(char *exp, char *str)
{
	int		index;
	char	**split;

	index = 0;
	split = (char**)malloc(sizeof(split) * 3);
	while (exp[index] && ft_strncmp(exp + index, str, ft_strlen(str)) != 0)
		index++;
	split[0] = ft_strndup(exp, index);
	split[1] = ft_strdup(exp + index + ft_strlen(str));
	split[2] = NULL;
	return (split);
}

char		**exp_split_index(char *exp, int index)
{
	char	**split;

	split = (char**)malloc(sizeof(split) * 3);
	split[0] = ft_strndup(exp, index);
	split[1] = ft_strdup(exp + index + 1);
	split[2] = NULL;
	return (split);
}
