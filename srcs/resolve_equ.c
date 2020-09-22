/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_equ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:58:12 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	replace_func_var(char *value, char *func_var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (value[i] && func_var)
	{
		if (ft_strncmp(value + i, func_var, ft_strlen(func_var)) == 0)
		{
			j = ft_strlen(func_var);
			while (j > 0 && value[i + j - 1])
			{
				value[i + j - 1] = 'X';
				j--;
			}
		}
		i++;
	}
}

static void	replace_equ_var(char *value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (value[i])
	{
		if (!ft_isdigit(value[i]) && value[i] != '+' && value[i] != '-'
			&& value[i] != '*' && value[i] != '/' && value[i] != '%'
			&& value[i] != ' ' && value[i] != '^' && value[i] != '=')
		{
			value[i] = 'X';
		}
		i++;
	}
}

static char	*find_name(char *name)
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
			{
				value = ft_strdup(current_var->value);
				replace_func_var(value, current_var->func_var);
			}
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

void		resolve_equ(char *name, char *exp)
{
	char	**split;
	char	*equ_str;
	char	*finded_name;
	char	*finded_exp;

	split = ft_strsplit(exp, '?');
	if (split && split[0])
	{
		finded_name = find_name(name);
		finded_exp = find_name(split[0]);
		if (finded_name && finded_exp)
		{
			equ_str = (char*)malloc(sizeof(equ_str)
				* ft_strlen(finded_name) + ft_strlen(finded_exp) + 4);
			if (equ_str)
			{
				ft_strcpy(equ_str, finded_name);
				ft_strcpy(equ_str + ft_strlen(finded_name), " = ");
				ft_strcpy(equ_str + ft_strlen(finded_name) + 3, finded_exp);
				replace_equ_var(equ_str);
				ft_computor(equ_str, 0);
				free(equ_str);
			}
			free(finded_name);
			free(finded_exp);
		}
		free_split(split);
	}
}
