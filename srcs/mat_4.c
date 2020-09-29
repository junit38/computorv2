/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 17:53:44 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

double		**add_mat(double **mat, int mat_len, double **mat2, int mat_len_2)
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
	while (mat[i] && mat2[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * mat_len);
		while (j < mat_len && j < mat_len_2)
		{
			new_mat[i][j] = mat[i][j] + mat2[i][j];
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		**minus_mat(double **mat, int mat_len, double **mat2, int mat_len_2)
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
	while (mat[i] && mat2[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * mat_len);
		while (j < mat_len && j < mat_len_2)
		{
			new_mat[i][j] = mat[i][j] - mat2[i][j];
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		**divide_mat(double **mat, int len, double **mat2, int len2)
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
	while (mat[i] && mat2[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * len);
		while (j < len && j < len2)
		{
			new_mat[i][j] = mat[i][j] / mat2[i][j];
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		**modulo_mat(double **mat, int len, double **mat2, int len2)
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
	while (mat[i] && mat2[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * len);
		while (j < len && j < len2)
		{
			new_mat[i][j] = (int)mat[i][j] % (int)mat2[i][j];
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}

double		**multiply_mat(double **mat, int len, double **mat2, int len2)
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
	while (mat[i] && mat2[i])
	{
		j = 0;
		new_mat[i] = (double*)malloc(sizeof(**new_mat) * len);
		while (j < len && j < len2)
		{
			new_mat[i][j] = mat[i][j] * mat2[i][j];
			j++;
		}
		i++;
	}
	new_mat[i] = NULL;
	return (new_mat);
}
