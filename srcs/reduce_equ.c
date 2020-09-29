/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 14:53:48 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double		get_value_img(t_param *param)
{
	double		value;

	value = 0;
	if (param && param->sym == '+')
		value = get_value_img(param->left) + get_value_img(param->right);
	else if (param && param->sym == '-')
		value = get_value_img(param->left) - get_value_img(param->right);
	else if (param && param->sym == '%')
		value = (int)get_value_img(param->left)
		% (int)get_value_img(param->right);
	else if (param && param->sym == '*')
		value = get_value_img(param->left) * get_value_img(param->right);
	else if (param && param->sym == '/')
		value = get_value_img(param->left) / get_value_img(param->right);
	else if (param && param->value && !is_digit(param->value)
		&& param->value[0] != '-')
		return (recursive_power(find_value(param->value), param->power));
	else if (param && param->sym == 0 && param->value && param->value[0])
		return (recursive_power(atof(param->value), param->power));
	return (recursive_power(value, param->power));
}

double		get_value_noimg(t_param *param)
{
	double		value;

	value = 0;
	if (param && param->sym == '+')
		value = get_value_noimg(param->left) + get_value_noimg(param->right);
	else if (param && param->sym == '-')
		value = get_value_noimg(param->left) - get_value_noimg(param->right);
	else if (param && param->sym == '%')
		value = (int)get_value_noimg(param->left)
	% (int)get_value_noimg(param->right);
	else if (param && param->sym == '*')
		value = get_value_noimg(param->left) * get_value_noimg(param->right);
	else if (param && param->sym == '/')
		value = get_value_noimg(param->left) / get_value_noimg(param->right);
	else if (param && param->value && !is_digit(param->value)
		&& param->value[0] != '-')
		return (recursive_power(find_value(param->value), param->power));
	else if (param && param->sym == 0 && param->value)
	{
		if (param->isimg)
			return (0);
		return (recursive_power(atof(param->value), param->power));
	}
	return (recursive_power(value, param->power));
}

static int	get_b_img(t_param *param)
{
	if (is_img_squared(param))
		return (0);
	return (get_value_img(param) - get_value_noimg(param));
}

static int	get_a_img(t_param *param)
{
	int		img;

	img = 0;
	if (is_img_squared(param))
		img = get_value_img(param) - get_value_noimg(param);
	return (get_value_noimg(param) - img);
}

t_param		*reduce_equ(t_param *param, int freeparam)
{
	t_param		*new_param;
	int			val;

	new_param = init_param();
	new_param->right = init_param();
	new_param->right->right = init_param();
	new_param->right->left = init_param();
	new_param->right->right->value = ft_strdup("1");
	new_param->right->right->isimg = 1;
	new_param->right->right->sym = '*';
	new_param->right->left->value = ft_itoa(get_b_img(param));
	new_param->left = init_param();
	new_param->left->value = ft_itoa(get_a_img(param));
	val = atoi(new_param->right->left->value);
	if (val < 0)
	{
		free(new_param->right->left->value);
		new_param->right->left->value = ft_itoa(val * -1);
		new_param->sym = '-';
	}
	else
		new_param->sym = '+';
	if (freeparam)
		free_param(param);
	return (new_param);
}
