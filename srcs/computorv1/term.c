/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/04/26 13:53:36 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

static t_term	*ft_copy_term(t_term *term)
{
	t_term	*copy;

	copy = (t_term*)malloc(sizeof(term));
	if (copy)
	{
		copy->coef = term->coef;
		copy->power = term->power;
	}
	return (copy);
}

static int		ft_copy_term_action(t_term **terms, t_term *term, int i)
{
	terms[i] = ft_copy_term(term);
	terms[i]->coef = -terms[i]->coef;
	return (1);
}

static void		ft_add_term_action(t_part *part, t_term **terms, t_term *term)
{
	int		i;
	int		j;
	int		added;

	i = 0;
	j = 0;
	added = 0;
	if (part->terms[i]->power > term->power && ++j)
		added = ft_copy_term_action(terms, term, i);
	while (part->terms[i])
	{
		if (part->terms[i]->power < term->power)
			terms[j] = part->terms[i];
		else if (added == 0 && part->terms[i]->power < term->power)
			added = ft_copy_term_action(terms, term, j);
		else
			terms[j] = part->terms[i];
		i++;
		j++;
	}
	if (added == 0 && ++j)
		ft_copy_term_action(terms, term, j - 1);
	terms[j] = NULL;
}

t_term			**ft_add_term(t_part *part, t_term *term)
{
	t_term	**terms;

	terms = (t_term**)malloc(sizeof(t_term*) * (ft_termslen(part->terms) + 2));
	if (terms)
		ft_add_term_action(part, terms, term);
	return (terms);
}

t_term			**ft_suppr_term(t_part *part, int i)
{
	t_term	**terms;
	int		j;
	int		k;

	j = 0;
	k = 0;
	terms = (t_term**)malloc(sizeof(t_term*) * (ft_termslen(part->terms)));
	if (terms)
	{
		while (part->terms[j] != NULL)
		{
			if (j == i)
				free(part->terms[j]);
			else
			{
				terms[k] = part->terms[j];
				k++;
			}
			j++;
		}
		terms[k] = NULL;
	}
	return (terms);
}
