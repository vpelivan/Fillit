#include "fillit.h"

char *read_block(int fd)
{
    int file;
    char c;
    char *str;
    int i;

    i = 0;
    if ((file = read(fd, &c, 1)) < 0)
        return (NULL);
    if (!(str = ft_strnew(545)))
        return (NULL);
    while (file != '\0')
    {
        str[i] = c;
        i++;
        file = read(fd, &c, 1);
    }
    str[i] = '\0';
    return(str);
}

int        validation_blocks(char *block, int k)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (i + k < 20 + k)
    {
        if (block[i + k] == '#')
        {
            if ((i + k + 1) < (20 + k) && block[i + k + 1] == '#') // right side connection
                count++;
            if ((i + k - 1) >= (0 + k) && block[i + k - 1] == '#') // left side connection
                count++;
            if ((i + k + 5) < (20 + k) && block[i + k + 5] == '#') // lower connection
                count++;
            if ((i + k - 5) >= (0 + k) && block[i + k - 5] == '#') // upper connection
                count++;
        }
        i++;
    }
    if (count == 6 || count == 8) // cube has 8 connections, other figures have 6 connections
        return (1);
    return (0);
}

int        validation_charecter(char *block, int k)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i + k < 20 + k && block[i + k] != '\0')
    {
        if (block[i + k] == '#' || block[i + k] == '\n' || block[i + k] == '.')
            count++;
        i++;
    }
    if (count == 20)
        return (1);
    return (0);
}

int        check_string(char *block)
{
    int i;
    int k;

    i = 0;
    k = i;
    if(!block)
        return (0);
    while (block[i + k] != '\0')
    {
        if (!(validation_blocks(block, k) && validation_charecter(block, k)))
            return (0);
        i = 19;
        if (block[i + k] == '\n' && block[i + k + 1] == '\0')
            return (1);
        if (block[i + k] == '\n' && block[i + k + 1] == '\n'
            && (block[i + k + 2] == '.' || block[i + k + 2] == '#'))
            k = 21 + k;
        else
            return (0);
        i = 0;
    }
    return (1);
}

int count_block(char *str)
{
    int count;

    count = 0;
    while (*str != '\0')
    {
        if (*str ==  '#')
            count++;
        str++;
    }
    count = count / 4 ;
    return(count);
}

int ft_mapsize(int src)
{
    int rez;

    src = src * 4;
    while (1)
    {
        rez = 1;
        while (rez <= src/2)
        {
            if (rez * rez == src)
                return (rez);
            rez++;
        }
        src++;
    }
    return (rez);
}

char **minmap(int src)
{
    char **rez;
    int fd;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    fd = ft_mapsize(src);
    rez = (char **)malloc(sizeof(char *) * fd);
    if (!rez)
        return (NULL);
    while (i <= fd)
    {
        rez[i] = (char *) malloc(sizeof(char) * fd + 1);
        i++;
    }
    i--;
    while (j < fd)
    {
        k = 0;
        while (k < i)
        {
            rez[j][k] = '.';
            k++;
        }
        rez[j][k] = '\0';
        printf("%s\n", rez[j]);
        j++;
    }
    return (rez);
}

int        main(/*int ac, char **av*/)
{
    int fd;
    int size;
//    char *usage;

//    usage = "usage: fillit sample.fillit\n";
//    if (ac == 2)
//    {
//        fd = open(av[1], O_RDONLY);
        fd = open("test", O_RDONLY);
        size = ft_mapsize(count_block(read_block(fd)));
        printf("%i\n", size);
        if (check_string(read_block(fd)) == 0)
            printf("error\n");
        else
            printf("ok\n");
        close(fd);
//    }
//        else if (ac == 1)
//          ft_putstr(usage);
//       system("leaks -q fillit");
       return (0);
}
