/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equ.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/21 11:36:05 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

static void	ft_reduce_equ(t_equ *equ)
{
	int		i;
	int		j;
	int		finded;

	i = 0;
	while (equ->right->terms[i])
	{
		j = 0;
		finded = 0;
		while (equ->left->terms[j])
		{
			if (equ->left->terms[j]->power == equ->right->terms[i]->power)
			{
				equ->left->terms[j]->coef = equ->left->terms[j]->coef
					- equ->right->terms[i]->coef;
				equ->right->terms[i]->coef = 0;
				finded = 1;
			}
			j++;
		}
		i++;
	}
}

static void	ft_compact_equ(t_equ *equ)
{
	int		i;
	int		j;
	int		finded;

	i = ft_get_term_size(equ->left);
	while (i > 0 && equ->left->terms[i - 1])
	{
		j = 0;
		finded = 0;
		while (equ->left->terms[j] && finded == 0)
		{
			if (equ->left->terms[j]->coef != 0
				&& equ->left->terms[j] != equ->left->terms[i - 1]
				&& equ->left->terms[j]->power == equ->left->terms[i - 1]->power)
			{
				equ->left->terms[j]->coef = equ->left->terms[j]->coef
					+ equ->left->terms[i - 1]->coef;
				equ->left->terms[i - 1]->coef = 0;
				finded = 1;
			}
			j++;
		}
		i--;
	}
}

static void	ft_short_equ(t_equ *equ)
{
	int		i;

	i = ft_get_term_size(equ->right);
	while (i > 0)
	{
		ft_free_or_copy(equ, i - 1);
		i--;
	}
	ft_short_equ_zero(equ->left);
	ft_short_equ_zero(equ->right);
}

t_equ		*ft_get_equ(char *equ_str)
{
	t_equ	*equ;
	char	**split;

	equ = (t_equ*)malloc(sizeof(t_equ));
	equ->left = NULL;
	equ->right = NULL;
	if (equ)
	{
		split = ft_strsplit(equ_str, '=');
		if (ft_array_len(split) == 2)
		{
			equ->left = ft_get_part(split[0]);
			equ->right = ft_get_part(split[1]);
		}
		else
			ft_putstr("Bad format\n");
		ft_free_array(split);
	}
	return (equ);
}

void		ft_equ_action(t_equ *equ, int display)
{
	if (display)
	{
		ft_putstr("Non reduced form: ");
		ft_print_equ(equ);
	}
	ft_reduce_equ(equ);
	// ft_print_equ(equ);
	ft_compact_equ(equ);
	// ft_print_equ(equ);
	ft_short_equ(equ);
	ft_putstr("Reduced form: ");
	ft_print_equ(equ);
}
