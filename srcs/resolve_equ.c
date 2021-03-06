/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_equ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 14:47:51 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	replace_equ_var(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (!ft_isdigit(value[i]) && value[i] != '+' && value[i] != '-'
			&& value[i] != '*' && value[i] != '/' && value[i] != '%'
			&& value[i] != ' ' && value[i] != '^' && value[i] != '=')
		{
			value[i] = 'X';
		}
		i++;
	}
}

static void	resolve_equ_2(char *finded_name, char *finded_exp)
{
	char	*equ_str;

	equ_str = (char*)malloc(sizeof(equ_str)
		* ft_strlen(finded_name) + ft_strlen(finded_exp) + 4);
	if (equ_str)
	{
		ft_strcpy(equ_str, finded_name);
		ft_strcpy(equ_str + ft_strlen(finded_name), " = ");
		ft_strcpy(equ_str + ft_strlen(finded_name) + 3, finded_exp);
		replace_equ_var(equ_str);
		ft_computor(equ_str, 0);
		free(equ_str);
	}
}

void		resolve_equ(char *name, char *exp)
{
	char	**split;
	char	*finded_name;
	char	*finded_exp;

	split = ft_strsplit(exp, '?');
	if (split && split[0])
	{
		finded_name = find_name(name);
		finded_exp = find_name(split[0]);
		if (finded_name && finded_exp)
		{
			resolve_equ_2(finded_name, finded_exp);
			free(finded_name);
			free(finded_exp);
		}
		free_split(split);
	}
}
