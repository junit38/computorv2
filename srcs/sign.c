/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:58:52 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static int	is_sign(char *value, int index)
{
	int		i;

	i = index - 1;
	if (!value[i] || index == 0)
		return (0);
	while (value[i] && value[i] == ' ')
		i--;
	if (value[i] == '*' || value[i] == '/' || value[i] == '%')
		return (0);
	return (1);
}

int			is_sign_minus(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '-' && is_sign(value, i))
			return (1);
		i++;
	}
	return (0);
}

int			get_sign_minus_index(char *value)
{
	int		i;
	int		index;

	i = 0;
	index = -1;
	while (value[i] && index == -1)
	{
		if (value[i] == '-' && is_sign(value, i))
			index = i;
		i++;
	}
	return (index);
}
