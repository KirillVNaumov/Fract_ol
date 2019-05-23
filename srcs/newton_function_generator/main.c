#include "calc.h"

void        print_usage(void)
{
    printf("Usage: ./calc [-i/-d] [function (write as a continuation of 'f(x) = ')]\n");
    printf("The function suppose to be in polymonial form\n");
}

void        print_summand(t_calc *info)
{
    t_summand   *tmp;

    tmp = info->function;
    printf("Function:\n");
    while (tmp)
    {
        printf("Coefficient - %d\n", tmp->coefficient);
        printf("Power - %d\n\n", tmp->power);
        tmp = tmp->next;
    }
    tmp = info->derivative;
    printf("Derivative:\n");
    while (tmp)
    {
        printf("Coefficient - %d\n", tmp->coefficient);
        printf("Power - %d\n\n", tmp->power);
        tmp = tmp->next;
    }
}

void        optimize_summand(t_calc *info)
{
    t_summand  *new;
    t_summand  *tmp;
    t_summand  *tmp1;
    int     arr[10];
    int     i;

    i = 0;
    while (i < 10)
        arr[i++] = 0;
    tmp = info->function;
    new = NULL;
    while (tmp)
    {
        if (arr[tmp->power] == 1)
        {
            tmp = tmp->next;
            continue ;
        }
        if (tmp->power >= 10)
            error("Used coefficient is too large");
        arr[tmp->power] = 1;
        tmp1 = tmp->next;
        while (tmp1)
        {
            if (tmp1->power == tmp->power)
                tmp->coefficient += tmp1->coefficient;
            tmp1 = tmp1->next;
        }
        if (tmp->coefficient != 0)
            new = add_summand(new, tmp->coefficient, tmp->power);
        tmp = tmp->next;
    }
    // free(info->function);
    info->function = new;
}

void        create_derivative(t_calc *info)
{
    t_summand  *tmp;
    int         coefficient;
    int         power;

    tmp = info->function;
    info->derivative = NULL;
    while (tmp)
    {
        coefficient = tmp->coefficient * tmp->power;
        power = tmp->power - 1;
        if (coefficient != 0)
            info->derivative = add_summand(info->derivative, coefficient, power);
        tmp = tmp->next;
    }
}

int         main(int argc, char **argv)
{
    t_calc  info;
 
    if (argc == 2)
    {
        parse_input(argv, &info);
        optimize_summand(&info);
        create_derivative(&info);
        print_summand(&info);
        create_file(&info);
    }
    else
        print_usage();
}