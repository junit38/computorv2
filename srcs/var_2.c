/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 13:59:54 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static t_var	*find_func(char *name)
{
	char	**split;
	t_var	*finded;
	t_var	*curs;

	split = ft_strsplit(name, '(');
	finded = NULL;
	curs = g_data->vars;
	if (split)
	{
		while (curs && !finded)
		{
			if (ft_strcmp(clean_line(to_lower_case(split[0])), curs->name) == 0)
				finded = curs;
			curs = curs->next;
		}
		free_split(split);
	}
	return (finded);
}

t_var			*find_var(char *name)
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
	if (!finded)
		finded = find_func(name);
	return (finded);
}

static int		replace_var_2(t_var *var, t_var *curs)
{
	var->next = curs->next;
	free_var(curs);
	return (1);
}

void			replace_var(t_var *var)
{
	t_var	*curs;
	t_var	*prec;
	int		replaced;

	curs = g_data->vars;
	prec = g_data->vars;
	replaced = 0;
	if (var && var->name && curs && curs->name
		&& ft_strcmp(var->name, curs->name) == 0 && (g_data->vars = var))
		replaced = replace_var_2(var, curs);
	while (curs && !replaced)
	{
		if (var && var->name && curs->name && ft_strcmp(var->name, curs->name) == 0)
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

void			save_var(t_var *var)
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
