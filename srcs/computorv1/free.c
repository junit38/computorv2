/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/04/20 17:06:52 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

static void	ft_free_part(t_part *part)
{
	int		i;

	i = 0;
	while (part->terms[i] != NULL)
	{
		free(part->terms[i]);
		i++;
	}
	free(part->terms);
	free(part);
}

void		ft_free_equ(t_equ *equ)
{
	if (equ->left)
		ft_free_part(equ->left);
	if (equ->right)
		ft_free_part(equ->right);
	free(equ);
}
