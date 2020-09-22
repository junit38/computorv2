/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:56:47 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	reduce(t_param *param)
{
	char		*value;

	if (param->left && param->right && param->left->value
		&& param->right->value && is_digit(param->left->value)
		&& is_digit(param->right->value))
	{
		value = ft_ftoa(get_value(param));
		clean_param(param);
		param->value = value;
		param->left = NULL;
		param->right = NULL;
		param->sym = 0;
	}
	else if (param->value && find_var(param->value) != NULL)
	{
		value = ft_ftoa(get_value(param));
		free(param->value);
		param->value = value;
	}
	if (param->left)
		reduce(param->left);
	if (param->right)
		reduce(param->right);
}

int		can_be_reduced(t_param *param)
{
	int		ret;

	ret = 0;
	if (param->left && param->right && param->left->value
		&& param->right->value && is_digit(param->left->value)
		&& is_digit(param->right->value))
		return (1);
	if (param->value && find_var(param->value) != NULL)
		return (1);
	if (param->left)
		ret = ret | can_be_reduced(param->left);
	if (param->right)
		ret = ret | can_be_reduced(param->right);
	return (ret);
}

void	resolve_exp_2(t_var *var)
{
	if (ft_strcmp(var->type, "MAT") == 0)
		print_mat(var);
	else if (ft_strcmp(var->type, "FUNC") == 0)
	{
		while (can_be_reduced(var->param))
			reduce(var->param);
		print_func(var->param);
		ft_putchar('\n');
	}
	else if (ft_strcmp(var->type, "IMG") == 0)
	{
		if (var->reduced == 0)
		{
			reduce_equ(var);
			var->reduced = 1;
		}
		print_param(var->param);
		printf("\n");
	}
	else if (var->param && var->param->left && var->param->right)
		print_resolution(get_value(var->param));
	else if (var->param)
		print_resolution(get_value(var->param));
}

void	resolve_exp(t_var *var)
{
	if (ft_strcmp(var->type, "MAT") == 0)
	{
		var->mat = split_mat(var->value);
		var->mat_len = get_mat_len(var->value);
	}
	else if (var->param == NULL)
		var->param = split_value(clean_line(var->value));
	if (var->param && !check_param(var->param, var))
	{
		ft_putstr("computorv2: Error while parsing\n");
		var->error = 1;
	}
	else
		resolve_exp_2(var);
}

void	resolve_name(char *name)
{
	double		res;
	t_param		*param;

	param = split_value(clean_line(name));
	if (param && param->left && param->right)
	{
		res = get_value(param);
		print_resolution(res);
	}
	else if (param)
		print_resolution(get_value(param));
	if (param)
		free_param(param);
}
