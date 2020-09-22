/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equ.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/04/25 18:06:23 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

void	ft_short_equ_zero(t_part *part)
{
	int		i;
	t_term	**terms;

	i = 0;
	while (part->terms[i])
	{
		if (part->terms[i]->coef == 0)
		{
			terms = ft_suppr_term(part, i);
			free(part->terms);
			part->terms = terms;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_free_or_copy(t_equ *equ, int i)
{
	t_term	**terms;

	if (equ->right->terms[i]->coef == 0)
	{
		terms = ft_suppr_term(equ->right, i);
		free(equ->right->terms);
		equ->right->terms = terms;
	}
	else
	{
		terms = ft_add_term(equ->left, equ->right->terms[i]);
		free(equ->left->terms);
		equ->left->terms = terms;
		terms = ft_suppr_term(equ->right, i);
		free(equ->right->terms);
		equ->right->terms = terms;
	}
}
