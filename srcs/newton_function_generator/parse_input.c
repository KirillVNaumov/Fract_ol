/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:57:09 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/05 20:57:10 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int				identify_power(char **function)
{
	int			power;

	if (**function != '^')
		power = 1;
	else
	{
		++(*function);
		power = ft_atoi(*function);
		while (**function >= '0' && **function <= '9')
			++(*function);
	}
	return (power);
}

void			parse_function(char *function, t_calc *info)
{
	int		coefficient;
	int		power;

	while (*function)
	{
		coefficient = ft_atoi(function);
		if (coefficient == 0)
			coefficient = (*function == '-') ? -1 : 1;
		if (*function == '+' || *function == '-')
			++function;
		while (*function >= '0' && *function <= '9')
			++function;
		if (*function != 'x')
			power = 0;
		else
		{
			++function;
			power = identify_power(&function);
		}
		info->function = add_summand(info->function, coefficient, power);
	}
}

int				iterate_with_index(char *function, int i)
{
	if (function[i] == '+' || function[i] == '-')
		++i;
	if (function[i] == '+' || function[i] == '-' || function[i] == '\0')
		error("Parsing error");
	while (function[i] >= '0' && function[i] <= '9')
		++i;
	if (function[i] == 'x')
	{
		++i;
		if (function[i] == '^')
		{
			++i;
			if (function[i] < '0' || function[i] > '9')
				error("Parsing error");
			while (function[i] >= '0' && function[i] <= '9')
				++i;
		}
	}
	if (function[i] < '0' || function[i] > '9')
		if (function[i] != '-' && function[i] != '+' && function[i] != '\0')
			error("Parsing error");
	return (i);
}

void			parse_input(char *function, t_calc *info)
{
	int			i;

	if (ft_strchr(function, 'x') == NULL)
		error("The function is written in incorrect form");
	i = -1;
	while (function[++i])
		if (!((function[i] >= '0' && function[i] <= '9') || \
			function[i] == '+' || function[i] == '-' || \
			function[i] == '^' || function[i] == 'x'))
			error("The function caontains unrecognized symbols");
	i = 0;
	while (function[i])
		i = iterate_with_index(function, i);
	parse_function(function, info);
}
