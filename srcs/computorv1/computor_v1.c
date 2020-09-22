/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/21 11:09:57 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor_v1.h"

static int	ft_get_poly_deg(t_equ *equ)
{
	int		i;
	int		polynomial_degree;

	i = 0;
	polynomial_degree = 0;
	while (equ->left->terms[i])
	{
		if (equ->left->terms[i]->power > polynomial_degree)
			polynomial_degree = equ->left->terms[i]->power;
		i++;
	}
	return (polynomial_degree);
}

int	ft_check_str(char *equ_str)
{
	int		i;

	i = 0;
	while (equ_str[i] != '\0')
	{
		if (equ_str[i] != 'X' && equ_str[i] != '^' && equ_str[i] != ' '
			&& equ_str[i] != '.' && equ_str[i] != '=' && equ_str[i] != '*'
			&& equ_str[i] != '+' && equ_str[i] != '-')
		{
			if (!ft_isdigit(equ_str[i]))
				return (0);
		}
		if (equ_str[i + 1] && equ_str[i] == '-' && equ_str[i + 1] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (equ_str[i] != '\0')
	{
		if (equ_str[i] == 'X' && equ_str[i + 2] && equ_str[i + 1] == '^'
			&& equ_str[i + 2] == '-')
			return (0);
		i++;
	}
	return (1);
}

void		ft_poly_sup_action(void)
{
	ft_putstr("The polynomial degree is stricly greater than 2, ");
	ft_putstr("I can't solve.\n");
}

void		ft_computor(char *equ_str, int display)
{
	t_equ		*equ;
	int			poly_deg;

	if (!ft_check_str(equ_str))
		return (ft_putstr("Error in argument\n"));
	if ((equ = ft_get_equ(equ_str)) && equ->left && equ->right)
	{
		ft_equ_action(equ, display);
		printf("Polynomial degree: %d\n", poly_deg = ft_get_poly_deg(equ));
		if (poly_deg > 2)
			ft_poly_sup_action();
		else if ((poly_deg == 0 && equ->left->terms && equ->left->terms[0]
			&& equ->left->terms[0]->coef == 0 && !equ->right->terms[0])
			|| (!equ->left->terms[0] && !equ->right->terms[0]))
			ft_putstr("All the value of X is solution.\n");
		else if ((poly_deg == 0 && equ->left->terms && equ->left->terms[0]
			&& equ->left->terms[0]->coef != 0 && !equ->right->terms[0])
			|| (!equ->left->terms[0] && !equ->right->terms[0]))
			ft_putstr("There is no solution.\n");
		else if (poly_deg <= 0)
			ft_putstr("Equation must be badly formatted\n");
		else
			ft_solve_equ(equ, display);
	}
	ft_free_equ(equ);
}

int			computor_v1(int argc, char **argv)
{
	int		display;

	display = 0;
	if (argc >= 2)
	{
		display = ft_get_display(argv);
		if (ft_get_file(argv) == 1)
			ft_resolve_files(argv, display);
		else if (display && argc == 2)
			ft_read_command_line(display);
		else
			ft_resolve_args(argv, display);
	}
	else
		ft_read_command_line(display);
	return (0);
}
