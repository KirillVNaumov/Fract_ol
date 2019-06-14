/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:38:57 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/23 15:38:58 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

void			print_usage(void)
{
	ft_printf("Usage: ./calc ");
	ft_printf("[function (write as a continuation of 'f(x) = ')]\n");
	ft_printf("The function suppose to be in polymonial form\n");
}

int				add_up_coefficient(t_summand *list)
{
	int			coefficient;
	t_summand	*tmp;

	tmp = list->next;
	coefficient = 0;
	while (tmp)
	{
		if (tmp->power == list->power)
			coefficient += tmp->coefficient;
		tmp = tmp->next;
	}
	return (coefficient);
}

void			optimize_summand(t_calc *info)
{
	t_summand	*new;
	t_summand	*tmp;
	int			arr[10];
	int			i;

	i = 0;
	while (i < 10)
		arr[i++] = 0;
	tmp = info->function;
	new = NULL;
	while (tmp)
	{
		if (arr[tmp->power] != 1)
		{
			if (tmp->power >= 10)
				error("Used coefficient is too large");
			arr[tmp->power] = 1;
			tmp->coefficient += add_up_coefficient(tmp);
			if (tmp->coefficient != 0)
				new = add_summand(new, tmp->coefficient, tmp->power);
		}
		tmp = tmp->next;
	}
	info->function = new;
}

void			create_derivative(t_calc *info)
{
	t_summand	*tmp;
	int			coefficient;
	int			power;

	tmp = info->function;
	info->derivative = NULL;
	while (tmp)
	{
		coefficient = tmp->coefficient * tmp->power;
		power = tmp->power - 1;
		if (coefficient != 0)
			info->derivative = add_summand(info->derivative, \
											coefficient, power);
		tmp = tmp->next;
	}
}

int				main(int argc, char **argv)
{
	t_calc		info;

	if (argc == 2)
	{
		parse_input(str_to_low(clear_spaces(ft_strdup(argv[1]))), &info);
		optimize_summand(&info);
		create_derivative(&info);
		create_file(&info);
	}
	else
		print_usage();
}
