#include "calc.h"

void            parse_function(char *function, t_calc *info)
{
    int     coefficient;
    int     power;

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
            if (*function != '^')
                power = 1;
            else
            {
                ++function;
                power = ft_atoi(function);
                while (*function >= '0' && *function <= '9')
                    ++function;
            }
        }
        info->function = add_summand(info->function, coefficient, power);
    }
}

void            check_function(char *function, t_calc *info)
{
    int     i;

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
    }
    parse_function(function, info);
    return (function);
}

void        parse_input(char **argv, t_calc *info)
{
    if (ft_strlen(argv[1]) != 2 || argv[1][0] != '-' || (argv[1][1] != 'i' && argv[1][1] != 'd'))
        error("No indecation of derivative or integral");
    if (argv[1][1] == 'i')
        info->type = 2;
    else
        info->type = 1;
    check_function(str_to_low(clear_spaces(ft_strdup(argv[2]))), info);
}