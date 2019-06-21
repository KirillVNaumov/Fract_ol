/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:13:07 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/19 17:13:22 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

char		*clear_spaces(char *str)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			++j;
	new = (char *)malloc(sizeof(char) * (j + 1));
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ')
			new[j++] = str[i];
	new[j] = '\0';
	free(str);
	return (new);
}
