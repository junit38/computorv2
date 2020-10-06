/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/06 12:01:39 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int		get_val_noimg_bracket(t_param *param)
{
	int		ret;

	ret = 1;
	if (param && param->left && param->right && param->right->isimg
		&& (param->power % 4 == 0))
		return (-1);
	else if (param && param->left && param->right && param->right->isimg
		&& (param->power % 4 == 1))
		return (-1);
	else if (param && param->left && param->right && param->right->isimg
		&& (param->power % 2 == 0))
		return (1);
	if (param && param->left)
		ret = get_val_img_bracket(param->left);
	if (param && param->right)
		ret = get_val_img_bracket(param->right);
	return (ret);
}

int		is_img_squared_bracket(t_param *param)
{
	int		ret;

	ret = 0;
	// printf("param->right->isimg: %d\n", param->right->isimg);
	// printf("param->right->value: %s\n", param->right->value);
	if (param && param->left && param->right && param->right->isimg
		&& !param->left->isimg && param->power >= 2)
		ret = 1;
	if (param && param->left)
		ret = ret | is_img_squared_bracket(param->left);
	if (param && param->right)
		ret = ret | is_img_squared_bracket(param->right);
	return (ret);
}

int		get_val_img_bracket(t_param *param)
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
