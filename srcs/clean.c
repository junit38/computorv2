/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:37:52 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void		clean_vars(void)
{
	t_var	*current_var;
	t_var	*prec;

	current_var = g_data->vars;
	prec = current_var;
	if (current_var && current_var->error)
	{
		prec->next = current_var->next;
		g_data->vars = current_var->next;
		free_var(current_var);
		return ;
	}
	while (current_var)
	{
		if (current_var->error)
		{
			prec->next = current_var->next;
			free_var(current_var);
		}
		prec = current_var;
		current_var = current_var->next;
	}
}
