/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_summand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:16:45 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/19 17:17:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

t_summand	*add_summand(t_summand *list, int coefficient, int power)
{
	t_summand	*new;
	t_summand	*tmp;

	new = (t_summand *)malloc(sizeof(t_summand));
	new->coefficient = coefficient;
	new->power = power;
	new->next = NULL;
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
