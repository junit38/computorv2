/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 17:32:26 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static int		get_b_img(t_param *param)
{
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
	if (get_b_img(param) != 0)
	{
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
	if (get_a_img(param) != 0 || get_b_img(param) == 0)
	{
		new_param->left = init_param();
		new_param->left->value = ft_itoa(get_a_img(param));
	}
	else
		new_param->sym = 0;
	if (freeparam)
		free_param(param);
	return (new_param);
}
