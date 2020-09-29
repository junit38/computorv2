/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equ_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 12:42:10 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int			is_img_squared(t_param *param)
{
	int 	ret;

	ret = 0;
	if (param && param->left && param->right && param->right->isimg && param->power == 2)
		ret = 1;
	if (param && param->left)
		ret = ret | is_img_squared(param->left);
	if (param && param->right)
		ret = ret | is_img_squared(param->right);
	return (ret);
}
