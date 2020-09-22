/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_equ_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 17:44:03 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static char *dup_and_replace(t_var *current_var)
{
	char	*value;

	value = ft_strdup(current_var->value);
	replace_func_var(value, current_var->func_var);
	return (value);
}

char		*find_name(char *name)
{
	t_var	*current_var;
	char	**split;
	char	*value;

	current_var = NULL;
	value = NULL;
	if (ft_strchr(name, '('))
	{
		split = ft_strsplit(name, '(');
		if (split)
		{
			current_var = find_var(split[0]);
			if (current_var && ft_strcmp(current_var->type, "FUNC") == 0)
				value = dup_and_replace(current_var);
			free_split(split);
			if (value)
				return (value);
		}
	}
	else
		current_var = find_var(name);
	if (current_var)
		return (ft_strdup(current_var->value));
	return (ft_strdup(name));
}
