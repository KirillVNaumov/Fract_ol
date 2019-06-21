/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_and_derivative.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:21:40 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/21 14:21:43 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

COMPLEX		function(COMPLEX z)
{
	return (2 * z * z * z + 8);
}

COMPLEX		derivative(COMPLEX z)
{
	return (6 * z * z);
}
