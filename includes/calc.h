#ifndef CALC_H
# define CALC_H

# include "../libft/libft.h"
# include "math.h"
# include <fcntl.h>

typedef     struct s_summand
{
    int     coefficient;
    int     power;
    struct s_summand    *next;
}           t_summand;

typedef     struct s_calc
{
    t_summand   *function;
    t_summand   *derivative;
}           t_calc;

void        parse_input(char **argv, t_calc *info);
void        create_file(t_calc *info);

/*
**  UTILS
*/

char        *clear_spaces(char *str);
char        *str_to_low(char *str);
t_summand   *add_summand(t_summand *list, int coefficient, int power);

#endif