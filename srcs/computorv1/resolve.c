/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/05/16 11:47:28 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

static void	ft_get_a_b_c(t_equ *equ, double *a, double *b, double *c)
{
	int		i;

	i = 0;
	while (equ->left->terms[i])
	{
		if (equ->left->terms[i]->power == 0)
			*c = equ->left->terms[i]->coef;
		else if (equ->left->terms[i]->power == 1)
			*b = equ->left->terms[i]->coef;
		else if (equ->left->terms[i]->power == 2)
			*a = equ->left->terms[i]->coef;
		i++;
	}
}

static void	ft_get_delta_positive_sol(double a, double b, double d, int dis)
{
	ft_putstr("Discriminant is strictly positive, ");
	ft_putstr("the two solutions are:\n");
	if (dis)
	{
		printf("s1 = (-b - √Δ) / 2a\n");
		printf("s2 = (-b + √Δ) / 2a\n");
		printf("s1 = (%.1f - √%.1f) / %.1f\n", -b, d, (2 * a));
		printf("s2 = (%.1f + √%.1f) / %.1f\n", -b, d, (2 * a));
		printf("s1 = (%.1f - %.1f) / %.1f\n", -b, ft_sqrt(d), (2 * a));
		printf("s2 = (%.1f + %.1f) / %.1f\n", -b, ft_sqrt(d), (2 * a));
		printf("s1 = %.1f / %.1f\n", -b - ft_sqrt(d), (2 * a));
		printf("s2 = %.1f / %.1f\n", -b + ft_sqrt(d), (2 * a));
	}
	printf("s1 = %f\n", ((-b + ft_sqrt(d)) / (2 * a)));
	printf("s2 = %f\n", ((-b - ft_sqrt(d)) / (2 * a)));
}

static void	ft_solve_delta(double a, double b, double d, int display)
{
	if (d > 0)
		ft_get_delta_positive_sol(a, b, d, display);
	else if (d == 0)
	{
		ft_putstr("Discriminant is strictly equal to zero, ");
		ft_putstr("the solution is:\n");
		if (display)
		{
			printf("s1 = s2 = (-b / (2 * a))\n");
			printf("s1 = s2 = (%.1f / (2 * %.1f))\n", -b, a);
		}
		printf("s1 = s2 = %f\n", (-b / (2 * a)));
	}
	else
		ft_print_delta_neg(a, b, d, display);
}

static void	ft_solve_poly_deg_1(double c, double b, int display)
{
	printf("The solution is:\n");
	if (display)
	{
		printf("s1 = s2 = (-c / b)\n");
		printf("s1 = s2 = (%.1f / %.1f)\n", -c, b);
	}
	printf("s1 = s2 = %f\n", (-c / b));
}

void		ft_solve_equ(t_equ *equ, int display)
{
	double		a;
	double		b;
	double		c;
	double		d;

	a = 0;
	b = 0;
	c = 0;
	ft_get_a_b_c(equ, &a, &b, &c);
	if (display)
		printf("a = %.1f b = %.1f c = %.1f\n", a, b, c);
	d = (b * b) - (4 * a * c);
	if (display && a != 0)
	{
		printf("delta = b2 - 4ac\n");
		printf("delta = (%.1f)2 - (4 * %.1f * %.1f)\n", b, a, c);
		printf("delta = %.1f - (%.1f)\ndelta = %.1f\n", b * b, 4 * a * c, d);
	}
	if (a == 0)
		ft_solve_poly_deg_1(c, b, display);
	else
		ft_solve_delta(a, b, d, display);
}
