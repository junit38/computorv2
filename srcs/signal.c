/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 16:59:09 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

static void	sig_handler(int sig)
{
	if (sig == SIGINT || sig == SIGTERM)
	{
		free_data();
		exit(1);
	}
}

void		init_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);
}
