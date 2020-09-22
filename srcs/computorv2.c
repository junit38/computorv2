/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 15:59:03 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void		assign_var(char *name, char *exp)
{
	t_var	*current_var;

	current_var = NULL;
	if (check_var(clean_line(name), clean_line(exp)) == 0)
		return ;
	if (ft_strchr(exp, '?') == 0)
	{
		current_var = init_var(clean_line(name), exp);
		if (already_exist(current_var))
			replace_var(current_var);
		else
			save_var(current_var);
		resolve_exp(current_var);
	}
	else if (ft_strcmp(clean_line(exp), "?") == 0)
	{
		current_var = find_var(name);
		if (current_var)
			resolve_exp_2(current_var);
		else
			resolve_name(name);
	}
	else
		resolve_equ(clean_line(name), exp);
}

void		print_and_resolve(char *line)
{
	char	**split;
	char	*clean;
	char	*clean_2;

	clean = clean_tabs(get_clean_line(line));
	if (clean)
	{
		clean_2 = get_clean_line_2(clean);
		if (clean_2)
		{
			split = ft_strsplit(clean, '=');
			if (split)
			{
				if (!split[0] || !split[1])
					printf("computorv2: Error nothing to assign\n");
				else
				{
					assign_var(to_lower_case(split[0]), split[1]);
					clean_vars();
				}
				free_split(split);
			}
			free(clean_2);
		}
		free(clean);
	}
}

void		read_command_line(void)
{
	int		exit;
	char	**line;

	exit = 0;
	line = (char**)malloc(sizeof(char*));
	while (!exit && get_next_line(0, line) > 0)
	{
		if (ft_strcmp(*line, "quit") == 0)
			exit = 1;
		else if (ft_strcmp(*line, "print") == 0)
			print_var();
		else
			print_and_resolve(*line);
		free(*line);
	}
	free(line);
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	init_signal();
	g_data = init_data();
	read_command_line();
	free_data();
	return (0);
}
