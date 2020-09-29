/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 16:37:17 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double		**multiply_mat_2(double a, double **mat, int mat_len)
{
	int		i;
	int		j;
	int		mat_hight;
	double	**new_mat;

	i = 0;
	while (mat[i])
		i++;
	mat_hight = i;
	i = 0;
	new_mat = (double**)malloc(sizeof(*new_mat) * mat_hight + 1);
	while (mat[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * mat_len);
		while (j < mat_len)
		{
			new_mat[i][j] = a * mat[i][j];
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		**divide_mat_2(double a, double **mat, int mat_len)
{
	int		i;
	int		j;
	int		mat_hight;
	double	**new_mat;

	i = 0;
	while (mat[i])
		i++;
	mat_hight = i;
	i = 0;
	new_mat = (double**)malloc(sizeof(*new_mat) * mat_hight + 1);
	while (mat[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * mat_len);
		while (j < mat_len)
		{
			new_mat[i][j] = mat[i][j] / a;
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		**modulo_mat_2(double a, double **mat, int mat_len)
{
	int		i;
	int		j;
	int		mat_hight;
	double	**new_mat;

	i = 0;
	while (mat[i])
		i++;
	mat_hight = i;
	i = 0;
	new_mat = (double**)malloc(sizeof(*new_mat) * mat_hight + 1);
	while (mat[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * mat_len);
		while (j < mat_len)
		{
			new_mat[i][j] = (int)mat[i][j] % (int)a;
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		get_product_mat(double **mat, int mat_len, double **mat2, int i, int j)
{
	int		y;
	double	res;

	res = 0;
	y = 0;
	while (y < mat_len)
	{
		if (mat[i] && mat[i][y] && mat2[y] && mat2[y][j])
			res += mat[i][y] * mat2[y][j];
		y++;
	}
	return (res);
}

double		**product_mat(double **mat, int mat_len, double **mat2, int mat_len_2)
{
	int		i;
	int		j;
	int		mat_hight;
	double	**new_mat;

	i = 0;
	while (mat2[i])
		i++;
	mat_hight = i;
	i = 0;
	new_mat = (double**)malloc(sizeof(*new_mat) * mat_hight + 1);
	while (mat[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * mat_len_2);
		while (j < mat_len_2)
		{
			new_mat[i][j] = get_product_mat(mat, mat_len, mat2, i, j);
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

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