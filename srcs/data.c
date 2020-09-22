/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:39:11 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

t_data		*init_data(void)
{
	t_data		*data;

	data = (t_data*)malloc(sizeof(*data));
	if (data)
	{
		data->vars = NULL;
	}
	return (data);
}

void		free_data(void)
{
	t_var		*curs;
	t_var		*next;

	curs = g_data->vars;
	while (curs)
	{
		next = curs->next;
		if (curs->name)
			free(curs->name);
		if (curs->value)
			free(curs->value);
		if (curs->param)
			free_param(curs->param);
		if (curs)
			free(curs);
		curs = next;
	}
	free(g_data);
}
