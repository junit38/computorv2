/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:52:17 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:39:19 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int		get_double_size(double n)
{
	double	x;
	int		size;
	int 	integer;

	x = n;
	size = 0;
	while (x > 0.1 && size < 7)
	{
		integer = x;
		x = x - integer;
		x = x * 10;
		size++;
	}
	return (size);
}

void	ft_ftoa_cpy(char *tmp, double f, char *n)
{
	double		x;
	int			integer;
	int			size;

	tmp = ft_strcpy(tmp, n);
	tmp[ft_strlen(n)] = '.';
	x = f;
	size = 0;
	integer = x;
	x = x - integer;
	x = x * 10;
	while (x > 0.1 && size < 7)
	{
		integer = x;
		tmp[ft_strlen(n) + size + 1] = 48 + integer;
		x = x - integer;
		x = x * 10;
		size++;
	}
	if (size == 0)
		tmp[ft_strlen(n)] = '\0';
	if (size == 7)
		tmp[ft_strlen(n) + size - 1]++;
	tmp[ft_strlen(n) + size + 1] = '\0';
}

char	*ft_ftoa(double f)
{
	
	char		*n;
	char		*tmp;
	int			integer;

	tmp = NULL;
	n = ft_itoa(f);
	if (n)
	{
		integer = f;
		f = f - integer;
		f = ft_abs(f);
		tmp = (char*)malloc(sizeof(tmp) * ft_strlen(n) + get_double_size(f));
		if (tmp)
			ft_ftoa_cpy(tmp, f, n);
		free(n);
	}
	return (tmp);
}
