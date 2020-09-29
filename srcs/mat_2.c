/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 16:41:34 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int			get_mat_index(char *value)
{
	int		i;

	i = 0;
	while (value[i] && value[i] != '[')
		i++;
	if (value[i] != '[')
		return (-1);
	return (i);
}

int	 		get_mat_len_param(t_param *param)
{
	double		mat_len;

	mat_len = 0;
	if (param->sym == -1)
		mat_len = param->right->mat_len;
	else if (param && param->left && param->left->mat)
		mat_len = param->left->mat_len;
	else if (param && param->left && param->right->mat)
		mat_len = param->right->mat_len;
	return (mat_len);
}

double		**get_mat(t_param *param)
{
	double	**mat;

	mat = NULL;
	if (param && param->sym == '*')
		mat = multiply_mat_param(param);
	else if (param && param->sym == '+')
		mat = add_mat_param(param);
	else if (param && param->sym == '-')
		mat = minus_mat_param(param);
	else if (param && param->sym == '/')
		mat = divide_mat_param(param);
	else if (param && param->sym == '%')
		mat = modulo_mat_param(param);
	else if (param && param->sym == -1)
		mat = product_mat_param(param);
	return (mat);
}

double 		**ft_strdup_mat(double **mat, int mat_len)
{
	double 	**new_mat;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	new_mat = (double**)malloc(sizeof(*mat) * (get_table_len_double(mat) + 1));
	if (new_mat)
	{
		while (mat[i])
		{
			j = 0;
			new_mat[i] = (double*)malloc(sizeof(**mat) * mat_len);
			while (j < mat_len)
			{
				new_mat[i][j] = mat[i][j];
				j++;
			}
			i++;
		}
		new_mat[i] = NULL;
	}
	return (new_mat);
}
