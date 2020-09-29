/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/25 16:38:11 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	print_resolution(double f, int newline)
{
	if ((int)(fabs(f) * 1000000) % 10 > 0)
		printf("%f", f);
	else if ((int)(fabs(f) * 100000) % 10 > 0)
		printf("%.5f", f);
	else if ((int)(fabs(f) * 10000) % 10 > 0)
		printf("%.4f", f);
	else if ((int)(fabs(f) * 1000) % 10 > 0)
		printf("%.3f", f);
	else if ((int)(fabs(f) * 100) % 10 > 0)
		printf("%.2f", f);
	else if ((int)(fabs(f) * 10) % 10 > 0)
		printf("%.1f", f);
	else
		printf("%.0f", f);
	if (newline)
		printf("\n");
}
