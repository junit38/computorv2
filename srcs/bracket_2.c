/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 17:47:14 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

char		*clean_bracket(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '[' || str[i] == ']')
			str[i] = ' ';
		i++;
	}
	return (str);
}

void		set_bracket(t_param *param, char *value, int index, int index_end)
{
	param->bracket = 1;
	value[index] = ' ';
	value[index_end] = ' ';
}
