/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/17 15:56:02 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

void		ft_putdouble(double c)
{
	int		a;
	int		i;
	double	d;

	i = DOUBLE_PREC;
	d = c;
	a = c / 1;
	d = d - a;
	if (a == 0 && c < 0)
		ft_putchar('-');
	ft_putnbr(a);
	if (d != 0)
		ft_putchar('.');
	d = ft_abs(d);
	while (d != 0 && i > 0)
	{
		d = d * 10;
		a = d / 1;
		d = d - a;
		if (i == 5)
			d += (1.0 / (ft_recursive_power(10, i)));
		ft_putnbr(a);
		i--;
	}
}

static void	ft_print_term(t_term *term)
{
	ft_putdouble(ft_abs(term->coef));
	ft_putchar(' ');
	ft_putstr("* X^");
	ft_putnbr(term->power);
}

void	ft_print_part(t_part *part)
{
	int		i;

	i = 0;
	while (part->terms[i] != NULL)
	{
		if (i != 0 && part->terms[i]->coef >= 0)
			ft_putstr(" + ");
		else if (i != 0)
			ft_putstr(" - ");
		else if (i == 0 && part->terms[i]->coef < 0)
			ft_putstr("- ");
		ft_print_term(part->terms[i]);
		i++;
	}
	if (!part->terms[0])
		ft_putstr("0");
}

void		ft_print_equ(t_equ *equ)
{
	ft_print_part(equ->left);
	ft_putstr(" = ");
	ft_print_part(equ->right);
	ft_putchar('\n');
}
