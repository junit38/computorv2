/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:41:19 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	print_var(void)
{
	t_var	*var;

	var = g_data->vars;
	while (var)
	{
		ft_putstr(var->name);
		ft_putstr(" =");
		ft_putstr(var->value);
		ft_putchar('\n');
		resolve_exp_2(var);
		var = var->next;
	}
}
