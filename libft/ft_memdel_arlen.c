/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_arlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:24:52 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/05 21:58:28 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel_arlen(void **ar)
{
	char	**s;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	s = NULL;
	if (ar)
	{
		s = (char **)ar;
		while (ar[n] != NULL)
			n++;
		while (i < n)
		{
			ft_memdel((void **)&s[i]);
			i++;
		}
		ft_memdel((void **)&ar);
	}
}
