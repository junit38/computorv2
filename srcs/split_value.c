/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/30 18:55:20 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void		split_sign(t_param *param, char *value, int c)
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

void		split_str(t_param *param, char *value, char *str)
{
	char	**split;

	param->sym = -1;
	split = exp_split_str(value, str);
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

void		split_index(t_param *param, char *value, size_t index)
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

static void	set_bra_and_split(t_param *param, char *value, int i, int i_end)
{
	set_bracket(param, value, i, i_end);
	split_value_2(param, value);
}

void		split_brace(t_param *param, char *value)
{
	int		index;
	int		index_end;

	index = get_bracket_index_start(value);
	index_end = get_bracket_index_end(value);
	if (is_bracket_power(value) && index == 0
		&& get_power_index_last(value) - 1 == index_end)
	{
		param->power = get_power(value);
		clean_power(value);
		set_bra_and_split(param, value, index, index_end);
	}
	else if (index == 0 && (index_end + 1) == (int)ft_strlen(value))
		set_bra_and_split(param, value, index, index_end);
	else
	{
		if (get_split_index(value) < 0)
		{
			set_bracket(param, value, index, index_end);
			split_value_2(param, value);
		}
		else
			split_index(param, value, get_split_index(value));
	}
}
