/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 17:36:26 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double		**product_mat_param(t_param *param)
{
	double		**mat;
	double		**mat2;

	mat = NULL;
	if (param && param->left && param->left->mat
		&& param->right && param->right->mat)
	{
		mat = param->left->mat;
		mat2 = param->right->mat;
		mat = product_mat(param->left->mat, param->left->mat_len, param->right->mat, param->right->mat_len);
	}
	return (mat);
}
