/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/06 12:46:27 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	set_img_squared(t_param *param, int power)
{
	if (power > 1)
		param->power = param->power * power;
	if (param && param->left && param->right && (param->right->isimg
		|| param->left->isimg) && param->power >= 2)
	{
		param->left->power = param->left->power * param->power;
		param->right->power = param->right->power * param->power;
		param->power = 1;
	}
	else if (param && param->left && param->right && param->power >= 2
		&& (is_img(param->left) || is_img(param->right)))
	{
		set_img_squared_rec(param->left, 2);
		set_img_squared_rec(param->right, 2);
		param->power = 1;
	}
	else
	{
		if (param && param->left)
			set_img_squared(param->left, power);
		if (param && param->right)
			set_img_squared(param->right, power);
	}
}

static int	get_b_img(t_param *param)
{
	// printf("%f and %f\n", get_val_img(param, 0), get_val_noimg(param, 0));
	// printf("%f and %f\n", get_val_img(param, 0), get_val_noimg(param, 0));
	if (is_img_squared(param))
		return (get_val_img(param, 0) - get_val_noimg(param, 0));
	return (get_val_img(param, 1) - get_val_noimg(param, 1));
}

static int	get_a_img(t_param *param)
{
	return (get_val_noimg(param, 1));
}

void		reduce_equ_2(t_param *param, t_param *new_param)
{
	int			val;

	new_param->right = init_param();
	new_param->right->right = init_param();
	new_param->right->left = init_param();
	new_param->right->right->value = ft_strdup("1");
	new_param->right->right->isimg = 1;
	new_param->right->right->sym = '*';
	new_param->right->left->value = ft_itoa(get_b_img(param));
	val = atoi(new_param->right->left->value);
	if (val < 0)
	{
		free(new_param->right->left->value);
		new_param->right->left->value = ft_itoa(val * -1);
		new_param->sym = '-';
	}
	else
		new_param->sym = '+';
}

t_param		*reduce_equ(t_param *param, int freeparam)
{
	t_param		*new_param;

	new_param = init_param();
	if (is_img_squared_bracket(param))
		set_img_squared(param, 1);
	if (get_b_img(param) != 0)
		reduce_equ_2(param, new_param);
	if (get_a_img(param) != 0 || get_b_img(param) == 0)
	{
		new_param->left = init_param();
		new_param->left->value = ft_itoa(get_a_img(param));
	}
	else if (new_param->sym == '+')
		new_param->sym = 0;
	if (freeparam)
		free_param(param);
	return (new_param);
}
