/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:13:43 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/19 17:13:52 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*str_to_header(char *str)
{
	str = str_to_low(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	return (str);
}
