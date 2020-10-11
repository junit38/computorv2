/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/11 13:57:09 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void		print_param_mat(t_param *param)
{
	if (param->left)
		print_param(param->left);
	if (param->sym && param->sym != -1)
		printf(" %c ", param->sym);
	if (param->sym == -1)
		printf(" ** ");
	if (param->right)
		print_param(param->right);
	if (param->value)
		printf("%s", param->value);
	if (param->mat && param->left && param->right)
		print_mat(param->mat, param->mat_len, 0);
	else
		print_mat(param->mat, param->mat_len, 1);
}

t_param		*ft_strdup_param(t_param *param)
{
	t_param		*new_param;

	new_param = init_param();
	if (new_param && param)
	{
		if (param->left)
			new_param->left = ft_strdup_param(param->left);
		if (param->right)
			new_param->right = ft_strdup_param(param->right);
		if (param->value)
			new_param->value = ft_strdup(param->value);
		if (param->mat && param->mat_len)
			new_param->mat = ft_strdup_mat(param->mat, param->mat_len);
		new_param->mat_len = param->mat_len;
		new_param->sym = param->sym;
		new_param->bracket = param->bracket;
		new_param->power = param->power;
		new_param->isfunc = param->isfunc;
		new_param->isimg = param->isimg;
	}
	return (new_param);
}
