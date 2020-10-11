/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/11 13:33:45 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static int	resolve_func_2(t_param *param, int is_resolution)
{
	if (is_resolution)
	{
		print_func(param);
		printf("\n");
	}
	else
	{
		ft_putstr("computor_v2: Error bad assign\n");
		return (-1);
	}
	return (1);
}

int			resolve_func(t_param *param, char *name, int is_resolution)
{
	char	*func_var;
	char	*func_replace;
	t_param	*param_2;
	int		ret;

	ret = 1;
	param_2 = split_value(clean_line(name));
	func_var = get_func_var(clean_line(name));
	func_replace = get_func_replace(clean_line(name));
	if (func_var && func_replace && ft_strcmp(func_var, func_replace) == 0
		&& !find_var(func_replace))
		ret = resolve_func_2(param, is_resolution);
	else
		print_resolution(get_value(param_2), 1);
	if (func_var)
		free(func_var);
	free_param(param_2);
	return (ret);
}

static void	*exit_resolve_param_2(t_param *param)
{
	if (param)
		free_param(param);
	ft_putstr("computor_v2: Error bad assign\n");
	return (NULL);
}

t_param		*resolve_param_2(t_param *param, char *func_var, char *func_replace)
{
	t_param		*tmp_param;
	t_var		*tmp_var;

	tmp_param = param;
	tmp_var = find_var(param->value);
	if (!tmp_var && !func_var)
		return (exit_resolve_param_2(param));
	if (tmp_var && tmp_var->param)
	{
		tmp_param = ft_strdup_param(tmp_var->param);
		if (tmp_param && ft_strcmp(tmp_var->type, "FUNC") == 0)
		{
			tmp_param->isfunc = 1;
			func_var = get_func_var(clean_line(param->value));
			func_replace = get_func_replace(clean_line(param->value));
			if (func_var && func_replace)
				tmp_param = resolve_param(tmp_param, func_var, func_replace);
			if (func_var)
				free(func_var);
		}
		if (tmp_param && param && param->power)
			tmp_param->power = param->power * tmp_param->power;
		free_param(param);
	}
	return (tmp_param);
}

t_param		*resolve_param(t_param *param, char *func_var, char *func_replace)
{
	t_param		*tmp_param;

	tmp_param = param;
	if (func_var && func_replace && !is_digit(func_var) && !find_var(func_var)
		&& ft_strcmp(func_var, func_replace) != 0)
		return (exit_resolve_param_2(param));
	if (param && param->value && func_replace
		&& ft_strcmp(param->value, func_replace) == 0)
	{
		free(param->value);
		param->value = ft_strdup(func_var);
	}
	else if (param && param->value && !is_digit(param->value)
		&& param->value[0] != '-')
		tmp_param = resolve_param_2(param, func_var, func_replace);
	if (tmp_param == param && param && param->left != NULL)
		param->left = resolve_param(param->left, func_var, func_replace);
	if (tmp_param == param && param && param->right != NULL)
		param->right = resolve_param(param->right, func_var, func_replace);
	return (tmp_param);
}
