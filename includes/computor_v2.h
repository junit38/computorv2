/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/03 15:55:10 by mery             ###   ########.fr       */
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
int			get_split_index(char *value);

/*
** BRACKET_2
*/
char		*clean_bracket(char *str);
void		set_bracket(t_param *param, char *value, int index, int index_end);
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
char		**exp_split_str(char *exp, char *str);

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
char		*get_func_replace(char *var);

/*
** GET_VALUE
*/
double		get_value(t_param *param);
double		find_value(char *value);
double		get_func_value(t_var *finded, char *func_var, t_param *param);

/*
** MAT
*/
void		free_mat(double **mat);
double		**split_mat(char *value);
int			get_mat_len(char *value);
int			get_mat_hight(char *value);
void		print_mat(double **mat, int mat_len, int newline);

/*
** MAT_2
*/
int			get_mat_index(char *value);
int			get_mat_len_param(t_param *param);
double		**get_mat(t_param *param);
double		**ft_strdup_mat(double **mat, int mat_len);

/*
** MAT_3
*/
double		**multiply_mat_param(t_param *param);
double		**add_mat_param(t_param *param);
double		**minus_mat_param(t_param *param);
double		**divide_mat_param(t_param *param);
double		**modulo_mat_param(t_param *param);

/*
** MAT_4
*/
double		**add_mat(double **mat, int len, double **mat2, int len_2);
double		**minus_mat(double **mat, int len, double **mat2, int len_2);
double		**divide_mat(double **mat, int len, double **mat2, int len_2);
double		**modulo_mat(double **mat, int len, double **mat2, int len_2);
double		**multiply_mat(double **mat, int len, double **mat2, int len_2);

/*
** MAT_5
*/
double		**multiply_mat_2(double a, double **mat2, int mat_len_2);
double		**divide_mat_2(double a, double **mat2, int mat_len_2);
double		**modulo_mat_2(double a, double **mat2, int mat_len_2);
double		**product_mat(double **mat, int len, double **mat2, int len2);

/*
** MAT_6
*/
double		**product_mat_param(t_param *param);

/*
** PARAM
*/
t_param		*init_param(void);
void		free_param(t_param *param);
void		clean_param(t_param *param);
int			check_param(t_param *param, t_var *var);
void		print_param(t_param *param);

/*
** PARAM_2
*/
void		print_param_mat(t_param *param);
t_param		*ft_strdup_param(t_param *param);

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
int			get_power_index_last(char *value);

/*
** REDUCE_EQU
*/
t_param		*reduce_equ(t_param *param, int freeparam);

/*
** REDUCE_EQU_2
*/
double		get_val_img(t_param *par, int pow);
int			is_img_squared(t_param *param);
int			is_img_squared_bracket(t_param *param);
int			get_val_img_bracket(t_param *param);

/*
** REDUCE_EQU_3
*/
int			get_val_noimg_bracket(t_param *param);

/*
** RESOLUTION
*/
void		print_resolution(double f, int newline);

/*
** RESOLVE
*/
void		resolve_exp_2(t_var *var);
void		resolve_exp(t_var *var);
void		resolve_name(char *name);

/*
** RESOLVE_2
*/
int			is_mat(t_param *param);
int			is_img(t_param *param);
int			is_func_param(t_param *param);
t_param		*resolve_param(t_param *param, char *func_var, char *func_replace);

/*
** RESOLVE_3
*/
void		reduce_mat(t_param *param);
int			can_be_reduced_mat(t_param *param);
void		reduce(t_param *param);
int			can_be_reduced(t_param *param);

/*
** RESOLVE_3
*/
int			can_be_resolved(t_param *param);

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
void		split_sign(t_param *param, char *value, int c);
void		split_str(t_param *param, char *value, char *str);
void		split_index(t_param *param, char *value, size_t index);
void		split_brace(t_param *param, char *value);

/*
** SPLIT_VALUE_2
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
int			get_table_len_double(double **table);

/*
** VAR
*/
t_var		*init_var(char *var, char *exp);
void		free_var(t_var *var);
int			already_exist(t_var *var);

/*
** VAR_2
*/
t_var		*find_var(char *name);
void		replace_var(t_var *var);
void		save_var(t_var *var);

/*
** VAR_3
*/
char		*get_var_type(char *name, char *value);

#endif
