/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:51:40 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	free_mat(int **mat)
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

int		**split_mat(char *value)
{
	int			**split_mat;
	char		**split;
	char		**split_2;
	int			i;
	int			j;

	split_mat = NULL;
	split = ft_strsplit(value, ';');
	if (split)
	{
		i = 0;
		split_mat = (int**)malloc(sizeof(*split_mat)
			* get_table_len(split) + 1);
		while (split[i])
		{
			j = 0;
			split_2 = ft_strsplit(clean_bracket(split[i]), ',');
			if (split_2)
			{
				split_mat[i] = (int*)malloc(sizeof(split_mat)
					* get_table_len(split_2));
				while (split_2[j])
				{
					split_mat[i][j] = atoi(split_2[j]);
					j++;
				}
				free_split(split_2);
			}
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

void	print_mat(t_var *var)
{
	int			i;
	int			j;

	i = 0;
	while (var->mat[i])
	{
		j = 0;
		ft_putstr("[ ");
		while (j < var->mat_len)
		{
			ft_putnbr(var->mat[i][j]);
			if (j + 1 < var->mat_len)
				ft_putstr(" , ");
			j++;
		}
		ft_putstr(" ]\n");
		i++;
	}
}
