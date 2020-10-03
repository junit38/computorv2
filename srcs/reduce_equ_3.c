/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/03 15:55:00 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int			get_val_noimg_bracket(t_param *param)
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
