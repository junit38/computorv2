/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/03 15:54:36 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static double		get_val_img_2(t_param *par)
{
	if (par->isimg && (par->power % 2) == 0)
		return (0);
	return (recursive_power(atof(par->value), par->power));
}

double		get_val_img(t_param *par, int pow)
{
	double		value;

	value = 0;
	if (par && par->sym == '+')
		value = get_val_img(par->left, pow) + get_val_img(par->right, pow);
	else if (par && par->sym == '-')
		value = get_val_img(par->left, pow) - get_val_img(par->right, pow);
	else if (par && par->sym == '%')
		value = (int)get_val_img(par->left, pow)
		% (int)get_val_img(par->right, pow);
	else if (par && par->sym == '*')
		value = get_val_img(par->left, pow) * get_val_img(par->right, pow);
	else if (par && par->sym == '/')
		value = get_val_img(par->left, pow) / get_val_img(par->right, pow);
	else if (par && par->value && !is_digit(par->value)
		&& par->value[0] != '-')
		return (recursive_power(find_value(par->value), par->power));
	else if (par && par->sym == 0 && par->value && par->value[0])
		return (get_val_img_2(par));
	return (recursive_power(value, par->power));
}

int			is_img_squared(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->isimg && param->power >= 2)
		ret = 1;
	if (param && param->left)
		ret = ret | is_img_squared(param->left);
	if (param && param->right)
		ret = ret | is_img_squared(param->right);
	return (ret);
}

int			is_img_squared_bracket(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->left && param->right && param->right->isimg && !param->left->isimg
		&& param->power >= 2)
		ret = 1;
	if (param && param->left)
		ret = ret | is_img_squared(param->left);
	if (param && param->right)
		ret = ret | is_img_squared(param->right);
	return (ret);
}

int			get_val_img_bracket(t_param *param)
{
	int		ret;

	ret = 1;
	if (param && param->left && param->right && param->right->isimg
		&& (param->power % 2 == 0))
		return (0);
	if (param && param->left)
		ret = get_val_img_bracket(param->left);
	if (param && param->right)
		ret = get_val_img_bracket(param->right);
	return (ret);
}
