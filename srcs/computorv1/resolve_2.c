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

void	ft_print_delta_neg(double a, double b, double d, int display)
{
	ft_putstr("Discriminant is strictly negative, there ");
	ft_putstr("is no real solution, but there is two complexe one:\n");
	printf("s1 = (%.1f - i√%.1f) / %.1f\n", -b, d, (2 * a));
	printf("s2 = (%.1f + i√%.1f) / %.1f\n", -b, d, (2 * a));
	if (display)
	{
		printf("s1 = (%.1f / %.1f)", -b, (2 * a));
		printf(" - (√%.1f / %.1f) * i\n", ft_sqrt(ft_abs(d)), (2 * a));
		printf("s2 = (%.1f / %.1f)", -b, (2 * a));
		printf(" + (√%.1f / %.1f) * i\n", ft_sqrt(ft_abs(d)), (2 * a));
	}
	printf("s1 = %f", -b / (2 * a));
	printf("- %f * i\n", ft_sqrt(ft_abs(d)) / (2 * a));
	printf("s2 = %f", -b / (2 * a));
	printf(" + %f * i\n", ft_sqrt(ft_abs(d)) / (2 * a));
}
