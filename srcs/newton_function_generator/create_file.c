#include "calc.h"

char            *struct_to_code(t_summand *list)
{
    char        *answer;
    int         counter;

    answer = ft_strnew(1);
    while (list)
    {
        answer = ft_update(answer, ft_strjoin(answer, " "));
        if (list->coefficient > 0)
            answer = ft_update(answer, ft_strjoin(answer, "+"));
        answer = ft_update(answer, ft_strjoin(answer, ft_itoa(list->coefficient)));
        counter = 0;
        while (counter++ < list->power)
            answer = ft_update(answer, ft_strjoin(answer, " * z"));
        list = list->next;
    }
    return (answer);
}

void            create_file(t_calc *info)
{
    int         fd;
    FILE        *file;
    char        *function;
    char        *derivative;

    info->type = 1;

	file = fopen("function_and_derivative.c", "wb");
    fclose(file);
    function = struct_to_code(info->function);
    derivative = struct_to_code(info->derivative);
    fd = open("function_and_derivative.c", O_RDWR);
    ft_putstr_fd("#include \"fractol.h\"\n\n", fd);
    ft_putstr_fd("double complex\t\tfunction(double complex z)\n", fd);
    ft_putstr_fd("{\n\treturn (", fd);
    ft_putstr_fd(function, fd);
    ft_putstr_fd(");\n}\n", fd);
    ft_putstr_fd("double complex\t\tderivative(double complex z)\n", fd);
    ft_putstr_fd("{\n\treturn (", fd);
    ft_putstr_fd(derivative, fd);
    ft_putstr_fd(");\n}\n", fd);
    close(fd);
}
 