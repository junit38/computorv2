/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 14:48:30 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int		is_mat(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->mat)
		return (1);
	if (param && ((param->left && param->left->mat)
		|| (param->right && param->right->mat)))
		return (1);
	if (param && param->left)
		ret = ret | is_mat(param->left);
	if (param && param->right)
		ret = ret | is_mat(param->right);
	return (ret);
}

int		is_img(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && ((param->left && param->left->isimg)
		|| (param->right && param->right->isimg)))
		return (1);
	if (param && param->left)
		ret = ret | is_img(param->left);
	if (param && param->right)
		ret = ret | is_img(param->right);
	return (ret);
}

int		is_func_param(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->isfunc)
		return (1);
	if (param && param->left)
		ret = ret | is_func_param(param->left);
	if (param && param->right)
		ret = ret | is_func_param(param->right);
	return (ret);
}

t_param *resolve_param_2(t_param *param, char *func_var, char *func_replace)
{
	t_param		*tmp_param;
	t_var		*tmp_var;

	tmp_param = param;
	tmp_var = find_var(param->value);
	if (tmp_var)
	{
		tmp_param = ft_strdup_param(tmp_var->param);
		if (tmp_param && ft_strcmp(tmp_var->type, "FUNC") == 0)
		{
			tmp_param->isfunc = 1;
			func_var = get_func_var(clean_line(param->value));
			func_replace = get_func_replace(clean_line(param->value));
			tmp_param = resolve_param(tmp_param, func_var, func_replace);
			if (func_var)
				free(func_var);
		}
		if (param->power)
			tmp_param->power = param->power * tmp_param->power;
		free_param(param);
	}
	return (tmp_param);
}

t_param	*resolve_param(t_param *param, char *func_var, char *func_replace)
{
	t_param		*tmp_param;

	tmp_param = param;
	if (param && param->value && func_replace
		&& ft_strcmp(param->value, func_replace) == 0)
	{
		free(param->value);
		param->value = ft_strdup(func_var);
	}
	else if (param && param->value && !is_digit(param->value)
		&& param->value[0] != '-')
		tmp_param = resolve_param_2(param, func_var, func_replace);
	if (param && param->left != NULL)
		param->left = resolve_param(param->left, func_var, func_replace);
	if (param && param->right != NULL)
		param->right = resolve_param(param->right, func_var, func_replace);
	return (tmp_param);
}
