/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 17:05:45 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static int	get_b_img(t_param *param)
{
	int		b;
	int		sign;

	b = 0;
	sign = 1;
	if (param->sym == '-')
		sign = -1;
	if (param && param->right && param->left && param->right->value
		&& param->left->value && (ft_strcmp(param->right->value, "i") == 0
		|| ft_strcmp(param->left->value, "i") == 0)
		&& param->sym == '*')
	{
		if (ft_strcmp(param->right->value, "i") == 0)
			b += atoi(param->left->value) * sign;
		else if (ft_strcmp(param->left->value, "i") == 0)
			b += atoi(param->right->value) * sign;
	}
	else
	{
		if (param && param->left)
			b += get_b_img(param->left);
		if (param && param->right)
			b += get_b_img(param->right);
	}
	return (b);
}

static int	get_a_img(t_param *param)
{
	int		a;
	int		sign;

	a = 0;
	sign = 1;
	if (param->sym == '-')
		sign = -1;
	if (param && param->right && param->left
		&& param->right->value && param->left->value
		&& (ft_strcmp(param->right->value, "i") == 0
		|| ft_strcmp(param->left->value, "i") == 0))
		return (0);
	if (param && param->left)
		a += get_a_img(param->left);
	if (param && param->right)
		a += get_a_img(param->right) * sign;
	if (param && param->value && param->sym == 0)
		a += atoi(param->value);
	return (a);
}

void		reduce_equ(t_var *var)
{
	t_param		*param;
	int			val;

	param = init_param();
	param->right = init_param();
	param->right->right = init_param();
	param->right->left = init_param();
	param->right->right->value = ft_strdup("i");
	param->right->right->sym = '*';
	param->right->left->value = ft_itoa(get_b_img(var->param));
	param->left = init_param();
	param->left->value = ft_itoa(get_a_img(var->param));
	val = atoi(param->right->left->value);
	if (val < 0)
	{
		free(param->right->left->value);
		param->right->left->value = ft_itoa(val * -1);
		param->sym = '-';
	}
	else
		param->sym = '+';
	free_param(var->param);
	var->param = param;
}
