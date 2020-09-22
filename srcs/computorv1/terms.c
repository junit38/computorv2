/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/05/16 11:30:06 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

size_t			ft_termslen(t_term **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int		ft_get_power(char *power_str)
{
	char	**split;
	int		atoi;

	split = ft_strsplit(power_str, '^');
	atoi = 0;
	if (split && ft_array_len(split) == 2)
		atoi = ft_atoi(split[1]);
	else if (ft_array_len(split) == 1)
		atoi = 1;
	ft_free_array(split);
	return (atoi);
}

static char		*ft_clean_coef(char *coef_str)
{
	int		i;

	i = 0;
	while (coef_str[i])
	{
		while (coef_str[i] != '-' && coef_str[i] != '\0')
			i++;
		if (coef_str[i] == '-')
		{
			if (coef_str[i + 1] && coef_str[i + 1] == ' ')
			{
				coef_str[i] = ' ';
				coef_str[i + 1] = '-';
			}
		}
		i++;
	}
	return (coef_str);
}

static t_term	*ft_get_term(char *term_str)
{
	t_term	*term;
	char	**split;

	term = (t_term*)malloc(sizeof(term));
	if (term)
	{
		split = ft_strsplit(term_str, '*');
		if (split && ft_array_len(split) >= 1)
		{
			if (ft_array_len(split) == 1 && ft_strchr(split[0], 'X'))
			{
				term->coef = (term_str[0] == '-') ? -1 : 1;
				term->power = split[0] ? ft_get_power(split[0]) : 0;
			}
			else
			{
				term->coef = ft_atod(ft_clean_coef(split[0]));
				term->power = split[1] ? ft_get_power(split[1]) : 0;
			}
		}
		ft_free_array(split);
	}
	return (term);
}

t_term			**ft_get_terms(char **list)
{
	t_term		**terms;
	int			i;

	i = 0;
	terms = (t_term**)malloc(sizeof(t_term*) * (ft_array_len(list) + 1));
	if (terms)
	{
		while (list[i])
		{
			terms[i] = ft_get_term(list[i]);
			i++;
		}
		terms[i] = NULL;
	}
	return (terms);
}
