/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 17:02:43 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

int			check_bracket(char *value)
{
	int		i;
	int		opened;

	i = 0;
	opened = 0;
	while (value[i])
	{
		if (value[i] == '(')
			opened++;
		if (value[i] == ')')
			opened--;
		i++;
	}
	if (opened != 0)
		return (0);
	return (1);
}

int			check_bracket_2(char *value)
{
	int		i;
	int		opened;

	i = 0;
	opened = 0;
	while (value[i])
	{
		if (value[i] == '[')
			opened++;
		if (value[i] == ']' && (!value[i + 1] || (value[i + 1]
			&& (value[i + 1] == ';' || value[i + 1] == ']'
				|| value[i + 1] == ' '))))
			opened--;
		i++;
	}
	if (opened != 0)
		return (0);
	return (1);
}

int			check_var(char *name, char *exp)
{
	if (ft_strcmp(clean_line(name), "i") == 0)
	{
		ft_putstr("computorv2: Variable 'i' not allowed\n");
		return (0);
	}
	if (!check_bracket(exp) || !check_bracket(name))
	{
		ft_putstr("computorv2: Error while parsing\n");
		return (0);
	}
	if (!check_bracket_2(exp) || !check_bracket_2(name))
	{
		ft_putstr("computorv2: Error while parsing\n");
		return (0);
	}
	if (is_digit(name))
	{
		ft_putstr("computorv2: Error bad assign\n");
		return (0);
	}
	return (1);
}
