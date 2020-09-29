/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 17:36:31 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double			**multiply_mat_2(double a, double **mat, int mat_len)
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

double			**divide_mat_2(double a, double **mat, int mat_len)
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

double			**modulo_mat_2(double a, double **mat, int mat_len)
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

static double	get_product_mat(double **mat, int mat_len, double **mat2, int i, int j)
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

double			**product_mat(double **mat, int len, double **mat2, int len2)
{
	int		i;
	int		j;
	double	**new_mat;

	i = 0;
	new_mat = (double**)malloc(sizeof(*new_mat) * get_table_len_double(mat) + 1);
	while (mat[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * len2);
		while (j < len2)
		{
			new_mat[i][j] = get_product_mat(mat, len, mat2, i, j);
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}
