/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:59:36 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void		split_sign(t_param *param, char *value, int c)
{
	char	**split;

	param->sym = c;
	split = exp_split(value, c);
	if (split)
	{
		if (split[0] && split[1])
		{
			param->left = split_value(clean_line(split[0]));
			param->right = split_value(clean_line(split[1]));
		}
		free_split(split);
	}
}

static void		split_index(t_param *param, char *value, size_t index)
{
	char	**split;

	param->sym = value[index];
	split = exp_split_index(value, index);
	if (split)
	{
		if (split[0] && split[1])
		{
			param->left = split_value(clean_line(split[0]));
			param->right = split_value(clean_line(split[1]));
		}
		free_split(split);
	}
}

static void		split_brace(t_param *param, char *value)
{
	size_t 	index;
	size_t 	index_end;

	index = get_bracket_index_start(value);
	index_end = get_bracket_index_end(value);
	if (is_bracket_power(value) && index == 0 && get_power_index_last(value) - 1 == index_end)
	{
		param->bracket = 1;
		param->power = get_power(value);
		value[index] = ' ';
		value[index_end] = ' ';
		clean_power(value);
		split_value_2(param, value);
	}
	else if (index == 0 && (index_end + 1) == ft_strlen(value))
	{
		param->bracket = 1;
		value[index] = ' ';
		value[index_end] = ' ';
		split_value_2(param, value);
	}
	else
	{
		index = get_split_index(value, index, index_end);
		split_index(param, value, index);
	}
}


void			split_value_2(t_param *param, char *value)
{
	if (ft_strchr(value, '+') != 0)
		split_sign(param, value, '+');
	else if (is_sign_minus(value))
		split_index(param, value, get_sign_minus_index(value));
	else if (ft_strchr(value, '*') != 0)
		split_sign(param, value, '*');
	else if (ft_strchr(value, '/') != 0)
		split_sign(param, value, '/');
	else if (ft_strchr(value, '%') != 0)
		split_sign(param, value, '%');
	else
	{
		if (ft_strchr(value, '^'))
			set_power(param, value);
		else
			param->value = ft_strdup(value);
	}
}

t_param			*split_value(char *value)
{
	t_param	*param;
	int		index;

	param = init_param();
	index = get_bracket_index(value);
	if (index != -1 && (index == 0 || (value[index - 1] && !ft_isalpha(value[index - 1]))))
		split_brace(param, value);
	else 
		split_value_2(param, value);
	return (param);
}
