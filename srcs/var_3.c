/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 13:57:44 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

char		*get_var_type(char *name, char *value)
{
	if (ft_strchr(name, '(') && ft_strchr(name, ')') != 0)
		return ("FUNC");
	else if (ft_strchr(value, 'i'))
		return ("IMG");
	else if (ft_strchr(value, '['))
		return ("MAT");
	return ("");
}
