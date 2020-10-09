/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/09 14:09:32 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

t_param	*init_param(void)
{
	t_param	*param;

	param = (t_param*)malloc(sizeof(*param));
	if (param)
	{
		param->left = NULL;
		param->right = NULL;
		param->value = NULL;
		param->mat = NULL;
		param->mat_len = 0;
		param->sym = 0;
		param->bracket = 0;
		param->power = 1;
		param->isfunc = 0;
		param->isimg = 0;
	}
	return (param);
}

void	free_param(t_param *param)
{
	if (param)
	{
		if (param->left)
			free_param(param->left);
		if (param->right)
			free_param(param->right);
		if (param->value)
			free(param->value);
		if (param->mat)
			free_mat(param->mat);
		if (param)
			free(param);
	}
}

void	clean_param(t_param *param)
{
	if (param)
	{
		if (param->left)
			free_param(param->left);
		if (param->right)
			free_param(param->right);
		if (param->value)
			free(param->value);
		if (param->mat)
			free_mat(param->mat);
	}
}

int		check_param(t_param *param, t_var *var)
{
	int		res_left;
	int		res_right;

	res_left = 1;
	res_right = 1;
	if (param->value && ft_strcmp(clean_line(param->value), var->name) == 0)
		return (0);
	if (param->left)
		res_left = check_param(param->left, var);
	if (param->right)
		res_right = check_param(param->right, var);
	return (res_left & res_right);
}

void	print_param(t_param *param)
{
	if (param && param->left)
		print_param(param->left);
	if (param && param->sym == '-' && !param->left)
		ft_putchar(param->sym);
	else if (param && param->sym && param->sym != '*' && param->sym != -1)
	{
		ft_putchar(' ');
		ft_putchar(param->sym);
		ft_putchar(' ');
	}
	if (param && param->sym == -1)
		ft_putstr(" ** ");
	if (param && param->right)
		print_param(param->right);
	if (param && param->isimg)
		ft_putstr("i");
	else if (param && param->value)
		ft_putstr(param->value);
	if (param && param->mat)
		print_mat(param->mat, param->mat_len, 0);
}
