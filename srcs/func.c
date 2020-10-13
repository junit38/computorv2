/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/10/13 11:31:25 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v2.h"

void	print_func(t_param *param)
{
	if (param->bracket)
		printf("(");
	if (param->left)
		print_func(param->left);
	if (param->sym && param->sym != -1)
		printf(" %c ", param->sym);
	if (param->sym == -1)
		printf(" ** ");
	if (param->right)
		print_func(param->right);
	if (param->isimg)
		printf("i");
	else if (param->value)
		printf("%s", param->value);
	if (param->mat)
		print_mat(param->mat, param->mat_len, 0);
	if (param->bracket)
		printf(")");
	if (param->power != 1)
	{
		ft_putchar('^');
		ft_putnbr(param->power);
	}
}

int		is_func(char *name)
{
	int		i;

	i = 0;
	while (name[i] && ft_isalpha(name[i]) && name[i] != '(')
		i++;
	if (!name[i] || name[i] != '(')
		return (0);
	i++;
	while (name[i] && name[i] != ')')
		i++;
	if (!name[i] || name[i] != ')')
		return (0);
	return (1);
}

char	*get_func_var(char *var)
{
	char		**split;
	char		**split2;
	char		*func_var;

	split = ft_strsplit(var, '(');
	func_var = NULL;
	if (split && split[1])
	{
		split2 = ft_strsplit(split[1], ')');
		if (split2 && split2[0])
		{
			func_var = ft_strdup(split2[0]);
			free_split(split2);
		}
		free_split(split);
	}
	return (func_var);
}

char	*get_func_name(char *var)
{
	char		**split;
	char		*name;

	split = ft_strsplit(var, '(');
	name = NULL;
	if (split && split[0])
	{
		name = ft_strdup(split[0]);
		free_split(split);
	}
	return (name);
}

char	*get_func_replace(char *var)
{
	char		**split;
	t_var		*finded;
	char		*func_replace;

	split = ft_strsplit(var, '(');
	func_replace = NULL;
	if (split && split[0])
	{
		finded = find_var(split[0]);
		if (finded)
			func_replace = finded->func_var;
		free_split(split);
	}
	return (func_replace);
}
