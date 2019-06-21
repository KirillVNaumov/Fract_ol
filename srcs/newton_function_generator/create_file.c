/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:50:18 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/21 14:10:27 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

char			*struct_to_code(t_summand *list)
{
	char		*answer;
	char		*str;
	int			counter;
	int			if_first;

	answer = ft_strnew(1);
	if_first = 1;
	while (list)
	{
		if (list->coefficient > 0 && if_first == 0)
			answer = ft_update(answer, ft_strjoin(answer, " + "));
		if (list->coefficient < 0)
			answer = ft_update(answer, ft_strjoin(answer, " - "));
		if_first = 0;
		str = ft_itoa(ft_abs(list->coefficient));
		answer = ft_update(answer, ft_strjoin(answer, str));
		free(str);
		counter = 0;
		while (counter++ < list->power)
			answer = ft_update(answer, ft_strjoin(answer, " * z"));
		list = list->next;
	}
	return (answer);
}

void			create_file(t_calc *info)
{
	int			fd;
	FILE		*file;
	char		*function;
	char		*derivative;

	file = fopen("srcs/fractol/fractals/function_and_derivative.c", "wb");
	fclose(file);
	function = struct_to_code(info->function);
	derivative = struct_to_code(info->derivative);
	fd = open("srcs/fractol/fractals/function_and_derivative.c", O_RDWR);
	ft_putstr_fd("#include \"fractol.h\"\n\n", fd);
	ft_putstr_fd("COMPLEX\t\tfunction(COMPLEX z)\n", fd);
	ft_putstr_fd("{\n\treturn (", fd);
	ft_putstr_fd(function, fd);
	ft_putstr_fd(");\n}\n", fd);
	ft_putstr_fd("COMPLEX\t\tderivative(COMPLEX z)\n", fd);
	ft_putstr_fd("{\n\treturn (", fd);
	ft_putstr_fd(derivative, fd);
	ft_putstr_fd(");\n}\n", fd);
	close(fd);
	free(function);
	free(derivative);
}
