/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:41:39 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	print_resolution(double f)
{
	if ((int)(fabs(f) * 1000000) % 10 > 0)
		printf("%f\n", f);
	else if ((int)(fabs(f) * 100000) % 10 > 0)
		printf("%.5f\n", f);
	else if ((int)(fabs(f) * 10000) % 10 > 0)
		printf("%.4f\n", f);
	else if ((int)(fabs(f) * 1000) % 10 > 0)
		printf("%.3f\n", f);
	else if ((int)(fabs(f) * 100) % 10 > 0)
		printf("%.2f\n", f);
	else if ((int)(fabs(f) * 10) % 10 > 0)
		printf("%.1f\n", f);
	else
		printf("%.0f\n", f);
}
