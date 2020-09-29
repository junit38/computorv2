/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_value_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 14:24:06 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	set_param_img(t_param *param)
{
	if (ft_strcmp(param->value, "i") == 0)
	{
		param->isimg = 1;
		free(param->value);
		param->value = ft_strdup("1");
	}
}

void		split_value_2(t_param *param, char *value)
{
	if (ft_strchr(value, '+') != 0)
		split_sign(param, value, '+');
	else if (is_sign_minus(value))
		split_index(param, value, get_sign_minus_index(value));
	else if (ft_strchr(value, '*') != 0 && ft_strchr(value, '*') != ft_strstr(value, "**"))
		split_sign(param, value, '*');
	else if (ft_strchr(value, '/') != 0)
		split_sign(param, value, '/');
	else if (ft_strchr(value, '%') != 0)
		split_sign(param, value, '%');
	else if (ft_strstr(value, "**") != 0)
		split_str(param, value, "**");
	else if (get_mat_index(value) == 0)
	{
		param->mat = split_mat(value);
		param->mat_len = get_mat_len(value);
	}
	else
	{
		if (ft_strchr(value, '^'))
			set_power(param, value);
		else
			param->value = ft_strdup(value);
		set_param_img(param);
	}
}

t_param		*split_value(char *value)
{
	t_param	*param;
	int		index;

	param = init_param();
	index = get_bracket_index(value);
	if (index != -1 && (index == 0
		|| (value[index - 1] && !ft_isalpha(value[index - 1]))))
		split_brace(param, value);
	else
		split_value_2(param, value);
	return (param);
}
