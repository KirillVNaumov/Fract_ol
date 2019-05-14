/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:00:19 by knaumov           #+#    #+#             */
/*   Updated: 2019/01/14 13:09:18 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clean_arr(char ***argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*argv)[i])
	{
		if (*argv)
			free(*argv);
		return ;
	}
	while ((*argv)[i])
		i++;
	while (j < i)
	{
		free((*argv)[j]);
		j++;
	}
	free(*argv);
}
