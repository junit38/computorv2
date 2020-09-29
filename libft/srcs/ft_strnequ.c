/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:09:29 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 10:19:08 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;
	int				eq;

	i = 0;
	eq = 1;
	while (s1[i] != '\0' && s2[i] != '\0' && eq == 1 && i < n)
	{
		if (s1[i] != s2[i])
			eq = 0;
		i++;
	}
	if (s1[i] != s2[i] && i != n)
		eq = 0;
	return (eq);
}
