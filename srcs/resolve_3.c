/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/13 15:25:19 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	reduce_mat_2(t_param *param)
{
	double	**mat;
	int		mat_len;

	mat = get_mat(param);
	mat_len = get_mat_len_param(param);
	clean_param(param);
	param->mat = mat;
	param->mat_len = mat_len;
	param->left = NULL;
	param->right = NULL;
	param->sym = 0;
}

void		reduce_mat(t_param *param)
{
	char	*value;

	if (param->left && param->right && (((param->left->value
		&& is_digit(param->left->value) && param->right->mat) ||
		(param->right->value && is_digit(param->right->value)
			&& param->left->mat)) || ((param->left && param->right
		&& param->left->mat && param->right->mat))))
		reduce_mat_2(param);
	else if (param->value && find_var(param->value) != NULL)
	{
		value = ft_ftoa(get_value(param));
		free(param->value);
		param->value = value;
	}
	if (param && param->left)
		reduce_mat(param->left);
	if (param && param->right)
		reduce_mat(param->right);
}

int			can_be_reduced_mat(t_param *param)
{
	int		ret;

	ret = 0;
	if (param->left && param->right && ((param->left->value
		&& is_digit(param->left->value) && param->right->mat) ||
		(param->right->value && is_digit(param->right->value)
			&& param->left->mat)))
		return (1);
	if (param->left && param->right && param->left->mat && param->right->mat)
		return (1);
	if (param->value && find_var(param->value) != NULL)
		return (1);
	if (param->left)
		ret = ret | can_be_reduced_mat(param->left);
	if (param->right)
		ret = ret | can_be_reduced_mat(param->right);
	return (ret);
}

void		reduce(t_param *param)
{
	char		*value;

	if (param->left && param->right && param->left->value
		&& param->right->value && is_digit(param->left->value)
		&& is_digit(param->right->value) && !param->left->isimg
		&& !param->right->isimg)
	{
		value = ft_ftoa(get_value(param));
		clean_param(param);
		param->value = value;
		param->left = NULL;
		param->right = NULL;
		param->sym = 0;
	}
	else if (param->value && find_var(param->value) != NULL)
	{
		value = ft_ftoa(get_value(param));
		free(param->value);
		param->value = value;
	}
	if (param->left)
		reduce(param->left);
	if (param->right)
		reduce(param->right);
}

int			can_be_reduced(t_param *param)
{
	int		ret;

	ret = 0;
	if (param->left && param->right && param->left->value
		&& param->right->value && is_digit(param->left->value)
		&& is_digit(param->right->value) && !param->left->isimg
		&& !param->right->isimg)
		return (1);
	if (param->value && find_var(param->value) != NULL)
		return (1);
	if (param->left)
		ret = ret | can_be_reduced(param->left);
	if (param->right)
		ret = ret | can_be_reduced(param->right);
	return (ret);
}
