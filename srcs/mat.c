/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 17:28:29 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	free_mat(double **mat)
{
	int		i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	if (mat)
		free(mat);
}

void	split_mat_2(double **split_mat, char **split, int i)
{
	char		**split_2;
	int			j;

	j = 0;
	split_2 = ft_strsplit(clean_bracket(split[i]), ',');
	if (split_2)
	{
		split_mat[i] = (double*)malloc(sizeof(split_mat)
			* get_table_len(split_2));
		while (split_2[j])
		{
			split_mat[i][j] = atoi(split_2[j]);
			j++;
		}
		free_split(split_2);
	}
}

double	**split_mat(char *value)
{
	double		**split_mat;
	char		**split;
	int			i;

	split_mat = NULL;
	split = ft_strsplit(value, ';');
	if (split)
	{
		i = 0;
		split_mat = (double**)malloc(sizeof(*split_mat)
			* get_table_len(split) + 1);
		while (split[i])
		{
			split_mat_2(split_mat, split, i);
			i++;
		}
		free_split(split);
		split_mat[i] = NULL;
	}
	return (split_mat);
}

int		get_mat_len(char *value)
{
	char		**split;
	char		**split_2;
	int			len;

	len = 0;
	split = ft_strsplit(value, ';');
	if (split)
	{
		split_2 = ft_strsplit(split[0], ',');
		if (split_2)
		{
			len = get_table_len(split_2);
			free_split(split_2);
		}
		free_split(split);
	}
	return (len);
}

void	print_mat(double **mat, int mat_len, int newline)
{
	int			i;
	int			j;

	i = 0;
	while (mat && mat[i])
	{
		j = 0;
		printf("[ ");
		while (j < mat_len)
		{
			print_resolution(mat[i][j], 0);
			if (j + 1 < mat_len)
				printf(" , ");
			j++;
		}
		printf(" ]");
		if (mat[i + 1] && newline)
			printf("\n");
		i++;
	}
}
