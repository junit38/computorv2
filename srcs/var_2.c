/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/23 12:20:13 by mery             ###   ########.fr       */
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

t_var		*find_var(char *name)
{
	t_var	*curs;
	t_var	*finded;

	curs = g_data->vars;
	finded = NULL;
	while (curs && !finded)
	{
		if (ft_strcmp(clean_line(to_lower_case(name)), curs->name) == 0)
			finded = curs;
		curs = curs->next;
	}
	return (finded);
}

static int	replace_var_2(t_var *var, t_var *curs)
{
	var->next = curs->next;
	free_var(curs);
	return (1);
}

void		replace_var(t_var *var)
{
	t_var	*curs;
	t_var	*prec;
	int		replaced;

	curs = g_data->vars;
	prec = g_data->vars;
	replaced = 0;
	if (ft_strcmp(var->name, curs->name) == 0)
	{
		g_data->vars = var;
		replaced = replace_var_2(var, curs);
	}
	while (curs && !replaced)
	{
		if (ft_strcmp(var->name, curs->name) == 0)
		{
			prec->next = var;
			replaced = replace_var_2(var, curs);
		}
		else
		{
			prec = curs;
			curs = curs->next;
		}
	}
}

void		save_var(t_var *var)
{
	t_var		*curs;

	curs = g_data->vars;
	if (curs == NULL)
	{
		g_data->vars = var;
		return ;
	}
	while (curs && curs->next)
		curs = curs->next;
	curs->next = var;
}
