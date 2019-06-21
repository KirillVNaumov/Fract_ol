/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_and_derivative.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:33:52 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/19 16:34:16 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

COMPLEX		function(COMPLEX z)
{
	return (5 * z * z * z - 1);
}

COMPLEX		derivative(COMPLEX z)
{
	return (15 * z * z);
}
