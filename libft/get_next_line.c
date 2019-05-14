/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:25:21 by knaumov           #+#    #+#             */
/*   Updated: 2019/02/22 15:43:12 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_from_fd_into_stock(int const fd, char **stock)
{
	static char	buff[BUFF_SIZE + 1] = { '\n' };
	int			read_bytes;
	char		*nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(*stock, buff);
		if (!nstr)
			return (-1);
		free(*stock);
		*stock = nstr;
	}
	return (read_bytes);
}

int		get_next_line(int const fd, char **line)
{
	static char	*stock = NULL;
	char		*endl_index;
	int			ret;

	if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	endl_index = ft_strchr(stock, '\n');
	while (endl_index == NULL)
	{
		ret = read_from_fd_into_stock(fd, &stock);
		if (ret == 0)
		{
			if ((endl_index = ft_strchr(stock, '\0')) == stock)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(stock, '\n');
	}
	*line = ft_strsub(stock, 0, endl_index - stock);
	if (!*line)
		return (-1);
	stock = ft_update(stock, ft_strdup(endl_index + 1));
	return (1);
}
