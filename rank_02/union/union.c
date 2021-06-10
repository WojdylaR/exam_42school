#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     checkb(char *str, char c, int l)
{
    int i;

    i = 0;
    while (i < l)
    {
        if (c == str[i])
            return (-1);
        i++;
    }
    return (1);
}

int     main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (checkb(argv[1], argv[1][i], i) == 1)
                write(1, &argv[1][i], 1);
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            if (checkb(argv[1], argv[2][i], ft_strlen(argv[1])) == 1 && checkb(argv[2], argv[2][i], i) == 1)
                write(1, &argv[2][i], 1);
            i++;

        }
    }
    write(1, "\n", 1);
}