/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/10 14:12:05 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

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
	if (param && param->isimg)
		return (1);
	if (param && param->left)
		ret = ret | is_img(param->left);
	if (param && param->right)
		ret = ret | is_img(param->right);
	return (ret);
}

int		can_be_resolved(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->value && !is_digit(param->value)
		&& param->value[0] != '-')
	{
		if (find_var(param->value))
			ret = 1;
	}
	if (param && param->left)
		ret = ret | can_be_resolved(param->left);
	if (param && param->right)
		ret = ret | can_be_resolved(param->right);
	return (ret);
}

int		is_null_param(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->sym != 0 && (param->left == NULL || param->right == NULL))
		ret = 1;
	if (param && param->left)
		ret = ret | is_null_param(param->left);
	if (param && param->right)
		ret = ret | is_null_param(param->right);
	return (ret);
}
