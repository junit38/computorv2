/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/09/17 15:55:43 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_V1_H
# define COMPUTOR_V1_H

# define DOUBLE_PREC 1;
# define SQRT_PREC 5;

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_term
{
	double			coef;
	int				power;
}					t_term;

typedef struct		s_part
{
	t_term			**terms;
}					t_part;

typedef struct		s_equ
{
	int				deg;
	t_part			*left;
	t_part			*right;
}					t_equ;

/*
** COMPUTOR_V1
*/
void				ft_computor(char *equ_str, int display);

/*
** COMPUTOR_V1_2
*/
int					ft_get_display(char **argv);
int					ft_get_file(char **argv);
void				ft_resolve_files(char **argv, int display);
void				ft_print_and_resolve(char *str, int display);

/*
** COMPUTOR_V1_3
*/
void				ft_resolve_args(char **argv, int display);
void				ft_read_command_line(int display);

/*
** EQU
*/
t_equ				*ft_get_equ(char *equ_str);
void				ft_equ_action(t_equ *equ, int display);

/*
** EQU_2
*/
void				ft_short_equ_zero(t_part *part);
void				ft_free_or_copy(t_equ *equ, int i);

/*
** FREE
*/
void				ft_free_equ(t_equ *equ);

/*
** GET_NEXT_LINE
*/
int					get_next_line(int const fd, char **line);

/*
** PARTS
*/
t_part				*ft_get_part(char *part_str);
int					ft_get_term_size(t_part *part);

/*
** PRINT
*/
void				ft_print_equ(t_equ *equ);
void				ft_putdouble(double c);
void				ft_print_part(t_part *part);

/*
** RESOLVE
*/
void				ft_solve_equ(t_equ *equ, int display);

/*
** RESOLVE 2
*/
void				ft_print_delta_neg(double a, double b, double d, int dis);

/*
** TERM
*/
t_term				**ft_add_term(t_part *part, t_term *term);
t_term				**ft_suppr_term(t_part *part, int i);

/*
** TERMS
*/
t_term				**ft_get_terms(char **list);
size_t				ft_termslen(t_term **array);

/*
** TOOLS
*/
void				ft_free_array(char **array);
size_t				ft_array_len(char **array);
double				ft_atod(char *str);
double				ft_abs(double c);

/*
** TOOLS_2
*/
double				ft_sqrt(double a);

#endif
