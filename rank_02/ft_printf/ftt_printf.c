#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int res;
int width;
int dot;

int ft_strlen(char *str)
{
    int x;

    x = 0;
    while (str[x])
        x++;
    return (x);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
    res++;
}

void    ft_putstr(char *str, int len)
{
    int x;

    x = 0;
    while (str[x] && len > 0)
    {
        ft_putchar(str[x]);
        x++;
        len--;
    }
}

char *ft_itoa(unsigned long nbr, int base)
{
    unsigned long tmp;
    int len;
    char *str;

    tmp = nbr;
    len = 0;
    str = NULL;
    if (nbr == 0)
        len++;
    while (tmp > 0)
    {
        tmp /= base;
        len++;
    }
    str = malloc(len + 1);
    str[len] = '\0';
    while (len > 0)
    {
        str[len - 1] = nbr % base;
        if (nbr % base > 9)
            str[len - 1] += 'a' - 10;
        else
            str[len - 1] += '0';
        nbr /= base;
        len--;
    }
    return (str);
}

void    print_d(int x)
{
    int len;
    char *str;
    int neg;

    neg = 0   ;
    if (x < 0)
    {
        neg = 1;
        x = x * (-1);
    }
    len = ft_strlen(str);
    if (dot != -1 && dot > len)
        len = dot;
    if (neg == 1 && width > 0)
        width--;
    while (width > len)
    {
        width--;
        ft_putchar(' ');
    }
    if (neg == 1)
        ft_putchar('-');
    while (len > ft_strlen(str))
    {
        len--;
        ft_putchar('0');
    }
    ft_putstr(str, ft_strlen(str));
    free(str);
}

void print_x(int x)
{
    int len;
    char *str;

    str = ft_itoa(x, 16);
    len = ft_strlen(str);
    if (len < dot && dot != -1)
        len = dot;
    while (width > len)
    {
        ft_putchar(' ');
        width--;
    }
    while (len > ft_strlen(str))
    {
        ft_putchar('0');
        len--;
    }
    ft_putstr(str, ft_strlen(str));
}

void print_s(char *str)
{
    int len;

    len = ft_strlen(str);
    if (len > dot && dot != -1)
        len = dot;
    while (width > len)
    {
        ft_putchar(' ');
        width--;
    }
    ft_putstr(str, len);
}

int ft_printf(char *str, ...)
{
    int x;
    va_list l;

    res = 0;
    va_start(l, str);
    x = 0;
    while (str[x])
    {
        if (str[x] == '%' || str[x + 1])
        {
            width = 0;
            dot = -1;
            x++;
            while (str[x] >= '0' && str[x] <= '9')
            {
                width = width * 10 + (str[x] - '0');
                x++;
            }
            if (str[x] == '.')
            {
                dot++;
                x++;
                while (str[x] >= '0' && str[x] <= '9')
                {
                    dot = dot * 10 + (str[x] - '0');
                    x++;
                }
            }
                if (str[x] == 's')
                    print_s(va_arg(l, char *));
                else if (str[x] == 'x')
                    print_x(va_arg(l, int));
                else if (str[x] == 'd')
                    print_d(va_arg(l, int));
                else
                    ft_putchar(str[x]);
            }
            else
                ft_putchar(str[x]);
            x++;
        }
    va_end(l);
    return (res);
}

int main()
{
    int x = -59;
    char *s = "Hello World !";
    int d = 54;

    printf("I'm the true  printf %4.6x, %6.2s, %5d\n", x, s, d);
    printf("I'm the false printf %4.6x, %6.2s, %5d", x, s, d);
}