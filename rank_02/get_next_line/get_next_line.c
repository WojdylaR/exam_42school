#include "get_next_line.h"

int get_next_line(char **line)
{
    int r;
    int l;
    int i;
    char *tmp;
    char c;

    l = 1;
    r = 0;
    if (!(*line = malloc(l)))
        return(-1);
    while (r = read(0, &c, 1) && l++ &&c != '\n')
    {
        if (!(tmp = malloc(l)))
        {
            free(*line);
            return (-1);
        }
        i = -1;
        while (++i < l - 2)
            tmp[i] = *line[i];
        tmp[i] = c;
        tmp[i + 1] = 0;
        free(*line);
        *line = tmp;
    }
    return (r);
}