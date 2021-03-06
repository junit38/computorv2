/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 14:43:41 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double		**multiply_mat_param(t_param *param)
{
	double		a;
	double		**mat;

	mat = NULL;
	if (!param || !param->left || !param->right)
		return (NULL);
	if (param->right->mat && param->left->value)
	{
		a = atof(param->left->value);
		mat = multiply_mat_2(a, param->right->mat, param->right->mat_len);
	}
	else if (param->left->mat && param->right->value)
	{
		a = atof(param->right->value);
		mat = multiply_mat_2(a, param->left->mat, param->left->mat_len);
	}
	else if (param->left->mat && param->right->mat)
		mat = multiply_mat(param->left->mat, param->left->mat_len,
			param->right->mat, param->right->mat_len);
	return (mat);
}

double		**add_mat_param(t_param *param)
{
	double		**mat;

	mat = NULL;
	if (param && param->left && param->left->mat
		&& param->right && param->right->mat)
	{
		mat = add_mat(param->left->mat,
			param->left->mat_len, param->right->mat, param->right->mat_len);
	}
	return (mat);
}

double		**minus_mat_param(t_param *param)
{
	double		**mat;

	mat = NULL;
	if (param && param->left && param->left->mat
		&& param->right && param->right->mat)
	{
		mat = minus_mat(param->left->mat, param->left->mat_len,
			param->right->mat, param->right->mat_len);
	}
	return (mat);
}

double		**divide_mat_param(t_param *param)
{
	double		a;
	double		**mat;

	mat = NULL;
	if (!param || !param->left || !param->right)
		return (NULL);
	if (param->right->mat && param->left->value)
	{
		a = atof(param->left->value);
		mat = divide_mat_2(a, param->right->mat, param->right->mat_len);
	}
	else if (param->left->mat && param->right->value)
	{
		a = atof(param->right->value);
		mat = divide_mat_2(a, param->left->mat, param->left->mat_len);
	}
	else if (param->left->mat && param->right->mat)
		mat = divide_mat(param->left->mat, param->left->mat_len,
			param->right->mat, param->right->mat_len);
	return (mat);
}

double		**modulo_mat_param(t_param *param)
{
	double		a;
	double		**mat;

	mat = NULL;
	if (!param || !param->left || !param->right)
		return (NULL);
	if (param->right->mat && param->left->value)
	{
		a = atof(param->left->value);
		mat = modulo_mat_2(a, param->right->mat, param->right->mat_len);
	}
	else if (param->left->mat && param->right->value)
	{
		a = atof(param->right->value);
		mat = modulo_mat_2(a, param->left->mat, param->left->mat_len);
	}
	else if (param && param->left && param->left->mat &&
		param->right && param->right->mat)
		mat = modulo_mat(param->left->mat, param->left->mat_len,
			param->right->mat, param->right->mat_len);
	return (mat);
}
