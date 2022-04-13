#include "ft_printf.h"

int rounding_direction(t_fs *f_str, long double f, int *for_bankers)
{
    int precision;
    
    if (f_str->is_precision)
        precision = f_str->precision;
    else
    {
        f_str->is_precision = 1;
        f_str->precision = 6;
        precision = f_str->precision;
    }
    while (precision) 
    {
        f -= (int)f;
        f *= 10;
        if (precision == 1)
            *for_bankers = (int)f;
        --precision;
    }
    /* Delete first digit one more time */
    f -= (int)f;
    if (f < 0.5)
        return (-1);
    else if (f == 0.5)
        return (0);
    return (1);
}

long double divide_one_with_ten_n(int precision)
{
    long double ret;

    ret = 1;
    while (precision)
    {
        ret /= 10;
        --precision;
    }
    return (ret);
}

long double round_up_float(int precision, long double f)
{
    long double add;

    add = divide_one_with_ten_n(precision);
    f += add;
    f -= add / 10;
    return (f);
}

/* Could i just use divide_one_with_ten_n and multiply with 5?? Would the result differ? */
long double divide_five_with_ten_n(int precision)
{
    long double ret;

    ret = 5;
    while (precision)
    {
        ret /= 10;
        --precision;
    }
    return (ret);
}

long double round_bankers(int precision, long double f, int next_to_last)
{
    if (next_to_last % 2 == 0)
        ;/* Just cut after precision when even? */
    else
        f += divide_five_with_ten_n(precision) / 10;
    return(f);
}

/* Just cut after precision when rounding down :D */
long double round_down_float(int precision, long double f)
{
    return (f);
}

/* Maybe should print all integers before coming here */
void print_whole_part(t_fs *f_str, long double *f)
{
    /* whole part isnt guaranteed to fit int ULL so do something else like get rid of fraction and start dividing */
}

void print_float(t_fs *f_str, long double f)
{
    int precision;
    unsigned long long digit;
    long double remainder;

    precision = f_str->precision;
    while (precision >= 0)
    {
        digit = f;
        ft_putnbr(digit);
        f -= digit;
        f *= 10;
        --precision;
    }
}

long double rounder(t_fs *f_str, long double f)
{
    int direction;
    int for_bankers;

    direction = rounding_direction(f_str, f, &for_bankers);
    if (direction == 1)
        return(round_up_float(f_str->precision, f));
    else if (direction == 0)
        return(round_bankers(f_str->precision, f, for_bankers));
    return(round_down_float(f_str->precision, f)); //At this moment does nothing because no need?
}

void float_to_ascii(t_fs *f_str)
{
    long double f;

    if (f_str->flags & LDBL)
        /*f = va_arg(f_str->argcs, long double)*/;
    else 
        f = va_arg(f_str->argcs, double);
    /*Check negativity */
    if (1 / f < 0)
        f_str->neg = 1;
    /*check for precision */
    print_float(f_str, rounder(f_str, f));
    ++f_str->str;
}