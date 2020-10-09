/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/09 14:09:41 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

t_var	*init_var(char *var, char *exp)
{
	t_var		*new_var;

	new_var = (t_var*)malloc(sizeof(*new_var));
	if (new_var)
	{
		new_var->func_var = NULL;
		new_var->type = get_var_type(var, exp);
		if (ft_strcmp(new_var->type, "FUNC") == 0)
		{
			new_var->name = get_func_name(var);
			new_var->func_var = get_func_var(var);
		}
		else
			new_var->name = ft_strdup(var);
		new_var->value = ft_strdup(exp);
		new_var->next = NULL;
		new_var->param = NULL;
		new_var->error = 0;
		new_var->reduced = 0;
	}
	return (new_var);
}

void	free_var(t_var *var)
{
	if (var)
	{
		if (var->name)
			free(var->name);
		if (var->value)
			free(var->value);
		if (var->func_var)
			free(var->func_var);
		if (var->param)
			free_param(var->param);
		free(var);
	}
}

int		already_exist(t_var *var)
{
	t_var		*curs;
	int			exist;

	curs = g_data->vars;
	exist = 0;
	while (curs)
	{
		if (ft_strcmp(var->name, curs->name) == 0)
			exist = 1;
		curs = curs->next;
	}
	return (exist);
}
