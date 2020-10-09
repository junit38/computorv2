/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/09 15:18:31 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	resolve_mat(t_param *param)
{
	while (can_be_reduced_mat(param))
		reduce_mat(param);
	print_param_mat(param);
	printf("\n");
}

void		resolve_exp_2(t_var *var)
{
	t_param		*param;

	if (var && ft_strcmp(var->type, "MAT") == 0)
		resolve_mat(var->param);
	else if (var && ft_strcmp(var->type, "FUNC") == 0)
	{
		param = resolve_param(var->param, var->func_var, NULL);
		while (param && can_be_reduced(param))
			reduce(param);
		print_func(param);
		printf("\n");
	}
	else if (var && ft_strcmp(var->type, "IMG") == 0)
	{
		param = reduce_equ(var->param, 0);
		print_param(param);
		printf("\n");
		free_param(param);
	}
	else if (var && var->param)
	{
		if (resolve_name(var->value) == -1)
			free_finded_var(var);
	}
}

void		resolve_exp(t_var *var)
{
	if (var->param == NULL)
		var->param = split_value(clean_line(var->value));
	if (var->param && !check_param(var->param, var))
	{
		ft_putstr("computorv2: Error while parsing\n");
		var->error = 1;
	}
	else
		resolve_exp_2(var);
}

static t_param 	*resolve_name_param(t_param *param)
{
	int		i;

	i = 0;
	param = resolve_param(param, NULL, NULL);
	while (param && can_be_resolved(param) && i < 100)
	{
		i++;
		param = resolve_param(param, NULL, NULL);
	}
	if (i == 100)
	{
		ft_putstr("computorv2: Maximum resolution reached\n");
		free_param(param);
		return (NULL);
	}
	return (param);
}

int			resolve_name(char *name)
{
	t_param		*param;

	param = split_value(clean_line(name));
	param = resolve_name_param(param);
	if (param == NULL)
		return (-1);
	if (is_img(param))
	{
		param = reduce_equ(param, 1);
		print_param(param);
		printf("\n");
	}
	else if (is_mat(param))
		resolve_mat(param);
	else if (is_func_param(param))
	{
		free_param(param);
		param = split_value(clean_line(name));
		print_resolution(get_value(param), 1);
	}
	else if (param)
		print_resolution(get_value(param), 1);
	if (param)
		free_param(param);
	return (1);
}
