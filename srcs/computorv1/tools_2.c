/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/19 12:33:06 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

double	ft_sqrt(double a)
{
	double	sqrt;
	double	sqrt_prec;
	double	precision;

	sqrt = 1;
	sqrt_prec = SQRT_PREC;
	precision = (1.0 / (ft_recursive_power(10, sqrt_prec)));
	while ((sqrt * sqrt) < a)
		sqrt += precision;
	sqrt -= precision;
	return (sqrt);
}

