/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/03 15:54:16 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static double	get_val_noimg_2(t_param *par, int pow)
{
	if (par->isimg && par->power > 1 && (par->power % 4) == 1 && pow == 1)
		return (1);
	if (par->isimg && par->power > 1 && (par->power % 2) == 1 && pow == 1)
		return (-1);
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

static int		get_b_img(t_param *param)
{
	printf("1: %f and %f\n", get_val_noimg(param, 1), get_val_img(param, 1));
	printf("0: %f and %f\n", get_val_noimg(param, 0), get_val_img(param, 0));
	if (is_img_squared(param))
		return (get_val_img(param, 0) - get_val_noimg(param, 0));
	else if (is_img_squared_bracket(param))
		return (get_val_img_bracket(param));
	return (get_val_img(param, 1) - get_val_noimg(param, 1));
}

static int		get_a_img(t_param *param)
{
	int		img;

	img = 0;
	if (is_img_squared(param))
		return (get_val_noimg(param, 1));
	else if (is_img_squared_bracket(param))
	{
		img = get_val_img(param, 1) - get_val_noimg(param, 1);
		img = img * get_val_noimg_bracket(param);
		return (get_val_noimg(param, 1) - img);
	}
	return (get_val_noimg(param, 1));
}

t_param			*reduce_equ(t_param *param, int freeparam)
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
