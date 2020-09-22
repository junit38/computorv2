/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v1_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2019/05/16 13:32:55 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

int			ft_get_display(char **argv)
{
	int		display;
	int		i;

	i = 0;
	display = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-v") == 0)
		{
			argv[i][0] = '\0';
			display = 1;
		}
		i++;
	}
	return (display);
}

int			ft_get_file(char **argv)
{
	int		file;
	int		i;

	i = 0;
	file = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-f") == 0)
		{
			argv[i][0] = '\0';
			file = 1;
		}
		i++;
	}
	return (file);
}

void		ft_print_and_resolve(char *str, int display)
{
	ft_putstr(str);
	ft_putstr(":\n");
	ft_putstr("---------\n");
	ft_computor(str, display);
}

static void	ft_print_not_found(char *name)
{
	ft_putstr("File not found: ");
	ft_putstr(name);
	ft_putstr("\n");
}

void		ft_resolve_files(char **argv, int display)
{
	int		i;
	int		fd;
	char	**line;

	i = 1;
	while (argv[i])
	{
		fd = -1;
		if (argv[i] && argv[i][0] != '\0')
			fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{
			line = (char**)malloc(sizeof(char*));
			while (get_next_line(fd, line) > 0)
			{
				ft_print_and_resolve(*line, display);
				free(*line);
			}
			free(line);
		}
		else if (argv[i] && argv[i][0] != '\0')
			ft_print_not_found(argv[i]);
		i++;
	}
}
