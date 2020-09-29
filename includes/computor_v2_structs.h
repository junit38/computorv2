/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v2_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/09/29 13:47:46 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_V2_STRUCTS_H
# define COMPUTOR_V2_STRUCTS_H

typedef struct		s_param
{
	struct s_param	*left;
	struct s_param	*right;
	char			*value;
	char			sym;
	int				bracket;
	int				power;
	double			**mat;
	int				mat_len;
	int				isfunc;
	int				isimg;
}					t_param;

typedef struct		s_var
{
	char			*name;
	char			*value;
	char			*type;
	char			*func_var;
	struct s_param	*param;
	struct s_var	*next;
	int				error;
	int				reduced;
}					t_var;

typedef struct		s_data
{
	t_var			*vars;
}					t_data;

#endif
