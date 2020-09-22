/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/04/26 13:36:19 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

static size_t	ft_digit_len(char *str)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			size++;
		i++;
	}
	return (size);
}

double			ft_atod(char *str)
{
	char	**split;
	double	value;
	double	tmp;

	value = 0;
	split = ft_strsplit(str, '.');
	{
		if (!split[1])
			value = (double)ft_atoi(split[0]);
		else
		{
			value = (double)ft_atoi(split[0]);
			tmp = (double)ft_atoi(split[1]);
			if (value < 0)
				tmp = -tmp;
			tmp = tmp / ft_recursive_power(10, ft_digit_len(split[1]));
			value += tmp;
		}
	}
	ft_free_array(split);
	return (value);
}

double			ft_abs(double c)
{
	if (c < 0)
		return (-c);
	return (c);
}

size_t			ft_array_len(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void			ft_free_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
