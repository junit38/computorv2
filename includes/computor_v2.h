/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/09/22 17:43:24 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_V2_H
# define COMPUTOR_V2_H

# include "computor_v2_structs.h"
# include "computor_v1.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <math.h>

t_data *g_data;

/*
** GET_NEXT_LINE
*/
int			get_next_line(int const fd, char **line);

/*
** BRACKET
*/
int			get_bracket_index_start(char *value);
int			get_bracket_index_end(char *value);
int			get_split_index(char *value, int start, int end);
char		*clean_bracket(char *str);
int			get_bracket_index(char *value);

/*
** CHECK
*/
int			check_var(char *name, char *exp);

/*
** CLEAN
*/
void		clean_vars(void);

/*
** CLEAN_LINE
*/
char		*get_clean_line(char *line);
char		*get_clean_line_2(char *line);

/*
** DATA
*/
t_data		*init_data(void);
void		free_data(void);

/*
** EXP_SPLIT
*/
char		**exp_split(char *exp, int c);
char		**exp_split_index(char *exp, int index);

/*
** FT_FTOA
*/
char		*ft_ftoa(double f);

/*
** FUNC
*/
void		print_func(t_param *param);
int			is_func(char *name);
char		*get_func_var(char *var);
char		*get_func_name(char *var);

/*
** GET_VALUE
*/
double		get_value(t_param *param);
double		find_value(char *value);

/*
** MAT
*/
void		free_mat(int **mat);
int			**split_mat(char *value);
int			get_mat_len(char *value);
int			get_mat_hight(char *value);
void		print_mat(t_var *var);

/*
** PARAM
*/
t_param		*init_param(void);
void		free_param(t_param *param);
void		clean_param(t_param *param);
int			check_param(t_param *param, t_var *var);
void		print_param(t_param *param);

/*
** PRINT
*/
void		print_var(void);

/*
** POWER
*/
void		set_power(t_param *param, char *value);
int			is_bracket_power(char *value);
int			get_power(char *value);
void		clean_power(char *value);
size_t		get_power_index_last(char *value);

/*
** REDUCE_EQU
*/
void		reduce_equ(t_var *var);

/*
** RESOLUTION
*/
void		print_resolution(double f);

/*
** RESOLVE
*/
void		resolve_exp_2(t_var *var);
void		resolve_exp(t_var *var);
void		resolve_name(char *name);

/*
** RESOLVE_EQU
*/
void		resolve_equ(char *name, char *exp);

/*
** RESOLVE_EQU_2
*/
char		*find_name(char *name);

/*
** SIGN
*/
int			is_sign_minus(char *value);
int			get_sign_minus_index(char *value);

/*
** SIGNAL
*/
void		init_signal(void);

/*
** SPLIT_VALUE
*/
t_param		*split_value(char *value);
void		split_value_2(t_param *param, char *value);

/*
** TOOLS
*/
void		free_split(char **split);
char		*to_lower_case(char *str);
int			is_digit(char *str);
char		*clean_line(char *str);
int			get_table_len(char **table);

/*
** TOOLS_2
*/
double		recursive_power(double nb, int power);
char		*clean_tabs(char *line);

/*
** VAR
*/
t_var		*init_var(char *var, char *exp);
void		free_var(t_var *var);
int			already_exist(t_var *var);

/*
** VAR_2
*/
char		*get_var_type(char *name, char *value);
t_var		*find_var(char *name);
void		replace_var(t_var *var);
void		save_var(t_var *var);

#endif
