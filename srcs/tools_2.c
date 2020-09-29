/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 16:41:19 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double	recursive_power(double nb, int power)
{
	if ((nb == 0) | (power < 0))
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb * ft_recursive_power(nb, (power - 1)));
}

char	*clean_tabs(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

int		get_table_len_double(double **table)
{
	int		i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}
