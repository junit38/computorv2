/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:51:32 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 17:09:35 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = (char*)malloc(sizeof(dup) * n);
	if (dup)
		dup = ft_strncpy(dup, str, n);
	return (dup);
}
