/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:21:58 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/23 15:21:59 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "../libft/libft.h"
# include "math.h"
# include <fcntl.h>

typedef struct			s_summand
{
	int					coefficient;
	int					power;
	struct s_summand	*next;
}						t_summand;

typedef struct			s_calc
{
	t_summand			*function;
	t_summand			*derivative;
}						t_calc;

void					parse_input(char *function, t_calc *info);
void					create_file(t_calc *info);

/*
**  UTILS
*/

char					*clear_spaces(char *str);
char					*str_to_low(char *str);
t_summand				*add_summand(t_summand *list, int coefficient, \
									int power);

#endif
