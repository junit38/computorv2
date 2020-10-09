/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/09 15:27:38 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int		is_func_param(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->isfunc)
		return (1);
	if (param && param->left)
		ret = ret | is_func_param(param->left);
	if (param && param->right)
		ret = ret | is_func_param(param->right);
	return (ret);
}

int		can_be_resolved(t_param *param)
{
	int		ret;

	ret = 0;
	if (param && param->value && !is_digit(param->value)
		&& param->value[0] != '-')
	{
		if (find_var(param->value))
			ret = 1;
	}
	if (param && param->left)
		ret = ret | can_be_resolved(param->left);
	if (param && param->right)
		ret = ret | can_be_resolved(param->right);
	return (ret);
}
