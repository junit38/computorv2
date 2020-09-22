/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:50:25 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double		get_func_value(t_var *finded, char *func_var, t_param *param)
{
	double		value;

	value = 0;
	if (param->sym == '+')
		value = get_func_value(finded, func_var, param->left)
		+ get_func_value(finded, func_var, param->right);
	else if (param->sym == '-')
		value = get_func_value(finded, func_var, param->left)
		- get_func_value(finded, func_var, param->right);
	else if (param->sym == '%')
		value = (int)get_func_value(finded, func_var, param->left)
		% (int)get_func_value(finded, func_var, param->right);
	else if (param->sym == '*')
		value = get_func_value(finded, func_var, param->left)
		* get_func_value(finded, func_var, param->right);
	else if (param->sym == '/')
		value = get_func_value(finded, func_var, param->left)
		/ get_func_value(finded, func_var, param->right);
	else if (ft_strcmp(param->value, finded->func_var) == 0)
	{
		value = find_value(func_var);
		if (value != 0)
			return (recursive_power(value, param->power));
		return (recursive_power(atof(func_var), param->power));
	}
	else if (!is_digit(param->value) && param->value[0] != '-')
		return (find_value(param->value));
	else if (param->sym == 0 && param->value && param->value[0])
		return (recursive_power(atof(param->value), param->power));
	return (recursive_power(value, param->power));
}

double		find_value(char *value)
{
	t_var		*curs;
	t_var		*finded;
	char		*name;
	char		*func_var;
	double		val;

	curs = g_data->vars;
	finded = NULL;
	func_var = NULL;
	while (curs && !finded)
	{
		name = clean_line(to_lower_case(value));
		if (is_func(name))
		{
			if (func_var)
				free(func_var);
			func_var = get_func_var(name);
			name = get_func_name(name);
			if (ft_strcmp(name, curs->name) == 0)
				finded = curs;
			if (name)
				free(name);
		}
		else if (ft_strcmp(name, curs->name) == 0)
			finded = curs;
		curs = curs->next;
	}
	if (finded && func_var)
	{
		val = get_func_value(finded, func_var, finded->param);
		free(func_var);
		return (val);
	}
	if (func_var)
		free(func_var);
	if (finded)
		return (get_value(finded->param));
	return (0);
}

double		get_value(t_param *param)
{
	double		value;

	value = 0;
	if (param->sym == '+')
		value = get_value(param->left) + get_value(param->right);
	else if (param->sym == '-')
		value = get_value(param->left) - get_value(param->right);
	else if (param->sym == '%')
		value = (int)get_value(param->left) % (int)get_value(param->right);
	else if (param->sym == '*')
		value = get_value(param->left) * get_value(param->right);
	else if (param->sym == '/')
		value = get_value(param->left) / get_value(param->right);
	else if (!is_digit(param->value) && param->value[0] != '-')
		return (find_value(param->value));
	else if (param->sym == 0 && param->value && param->value[0])
		return (recursive_power(atof(param->value), param->power));
	return (recursive_power(value, param->power));
}
