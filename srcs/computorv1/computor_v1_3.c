/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v1_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/05/16 13:34:24 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

void	ft_resolve_args(char **argv, int display)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0])
			ft_print_and_resolve(argv[i], display);
		i++;
	}
}

void	ft_read_command_line(int display)
{
	char	**line;

	line = (char**)malloc(sizeof(char*));
	while (get_next_line(0, line) > 0)
	{
		ft_print_and_resolve(*line, display);
		free(*line);
	}
	free(line);
}
