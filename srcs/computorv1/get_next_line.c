/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:36:35 by jmery             #+#    #+#             */
/*   Updated: 2019/04/26 14:50:14 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cat_and_realoc(char *tmp, char buf[], int ret)
{
	char	*tmp2;

	tmp2 = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + ret + 1));
	if (tmp2)
	{
		ft_strncpy(tmp2, tmp, ft_strlen(tmp));
		ft_strncat(tmp2, buf, ret);
	}
	free(tmp);
	return (tmp2);
}

static char	*ft_save_next_line(char buf[], int *ret)
{
	int		newline_index;
	char	*save;

	newline_index = 0;
	while (buf[newline_index] != '\n' && buf[newline_index])
		newline_index++;
	if (buf[newline_index] != '\n')
		return (NULL);
	save = (char*)malloc(sizeof(char) * (*ret - newline_index + 1));
	if (save)
		ft_strncpy(save, buf + newline_index + 1, *ret - newline_index - 1);
	return (save);
}

static char	*ft_get_line(char *tmp)
{
	char	*tmp2;
	int		newline_index;

	newline_index = 0;
	while (tmp[newline_index] != '\n' && tmp[newline_index])
		newline_index++;
	tmp2 = (char*)malloc(sizeof(char) * (newline_index + 1));
	if (tmp2)
		ft_strncpy(tmp2, tmp, newline_index);
	free(tmp);
	return (tmp2);
}

static char	*ft_load_next_line(int fd, char buf[], int *ret, int onsave)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * (*ret + 1));
	if (tmp)
		ft_strncpy(tmp, buf, *ret);
	while (!ft_strchr(tmp, '\n') && *ret > 0)
	{
		*ret = read(fd, buf, BUFF_SIZE);
		tmp = ft_cat_and_realoc(tmp, buf, *ret);
	}
	tmp = ft_get_line(tmp);
	(void)onsave;
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE];
	static char		*save;

	if (save && *save)
	{
		ft_strcpy(buf, save);
		ret = ft_strlen(save) + 1;
		free(save);
		*line = ft_load_next_line(fd, buf, &ret, 1);
		save = ft_save_next_line(buf, &ret);
		return (1);
	}
	else
	{
		if (save)
			free(save);
		save = NULL;
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
			return (ret);
		*line = ft_load_next_line(fd, buf, &ret, 0);
		save = ft_save_next_line(buf, &ret);
		return (1);
	}
	return (-1);
}
