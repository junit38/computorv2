/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/06 12:52:47 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static double	get_val_img_2(t_param *par)
{
	if (par->isimg && (par->power % 2) == 1)
		return (-1);
	if (par->isimg && (par->power % 4) == 1)
		return (1);
	if (par->isimg && (par->power % 2) == 0)
		return (0);
	return (recursive_power(atof(par->value), par->power));
}

double			get_val_img(t_param *par, int pow)
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

static double	get_val_noimg_2(t_param *par, int pow)
{
	if (par->isimg && (par->power % 4) == 0 && pow == 1)
		return (1);
	if (par->isimg && (par->power % 2) == 0 && pow == 1)
		return (-1);
	if (par->isimg)
		return (0);
	return (recursive_power(atof(par->value), par->power));
}

double			get_val_noimg(t_param *par, int pow)
{
	double		value;

	value = 0;
	if (par && par->sym == '+')
		value = get_val_noimg(par->left, pow) + get_val_noimg(par->right, pow);
	else if (par && par->sym == '-')
		value = get_val_noimg(par->left, pow) - get_val_noimg(par->right, pow);
	else if (par && par->sym == '%')
		value = (int)get_val_noimg(par->left, pow)
	% (int)get_val_noimg(par->right, pow);
	else if (par && par->sym == '*')
		value = get_val_noimg(par->left, pow) * get_val_noimg(par->right, pow);
	else if (par && par->sym == '/')
		value = get_val_noimg(par->left, pow) / get_val_noimg(par->right, pow);
	else if (par && par->value && !is_digit(par->value)
		&& par->value[0] != '-')
		return (recursive_power(find_value(par->value), par->power));
	else if (par && par->sym == 0 && par->value)
		return (get_val_noimg_2(par, pow));
	return (recursive_power(value, par->power));
}

void			set_img_squared_rec(t_param *param, int power)
{
	if (param->value)
		param->power = param->power * power;
	if (param && param->left)
		set_img_squared_rec(param->left, power);
	if (param && param->right)
		set_img_squared_rec(param->right, power);
}
