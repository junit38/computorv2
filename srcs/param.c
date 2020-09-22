/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:41:06 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

t_param *init_param(void)
{
	t_param	*param;

	param = (t_param*)malloc(sizeof(*param));
	if (param)
	{
		param->left = NULL;
		param->right = NULL;
		param->value = NULL;
		param->sym = 0;
		param->bracket = 0;
		param->power = 1;
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
		if (param)
			free(param);
	}
}

int 	check_param(t_param *param, t_var *var)
{
	int 		res_left;
	int 		res_right;

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
	if (param->left)
		print_param(param->left);
	if (param->sym && param->sym != '*')
		printf(" %c ", param->sym);
	if (param->right)
		print_param(param->right);
	if (param->value)
		printf("%s", param->value);
}
