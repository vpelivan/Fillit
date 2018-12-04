#include "Fillit.h"

char *read_block(int fd)
{
    int file;
    char c;
    char *str;
    int i;

    i = 0;
    if ((file = read(fd, &c, 1)) < 0)
        return (NULL);
    else
    {
        str = (char *)malloc(sizeof(char) * 545);
        while (file != '\0')
        {
            str[i] = c;
            i++;
            file = read(fd, &c, 1);
        }
        str[i] = '\0';
    }
    return (str);
}

int        validation_blocks(char *block, int k)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (i +k < 20 + k)
    {
        if (block[i + k] == '#')
        {
            if ((i + k + 1) < (20 + k) && block[i + k + 1] == '#')
                count++;
            if ((i + k - 1) >= (0 + k) && block[i + k - 1] == '#')
                count++;
            if ((i + k + 5) < (20 + k) && block[i + k + 5] == '#')
                count++;
            if ((i + k - 5) >= (0 + k) && block[i + k - 5] == '#')
                count++;
        }
        i++;
    }
    if (count == 6 || count == 8)
        return (1);
    return (0);
}

int        validation_charecter(char *block, int k)
{
    int symbol;
    int line;
    int point;
    int i;

    i = 0;
    symbol = 0;
    line = 0;
    point = 0;
    while (i + k < 20 + k && block[i + k] != '\0')
    {
        if (block[i + k] == '#')
            symbol++;
        if (block[i + k] == '\n')
            line++;
        if (block[i + k] == '.')
            point++;
        i++;
    }
    if (symbol == 4 && line == 4 && point == 12 )
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

int        main()
{
    int fd;
    fd = open("./test", O_RDONLY);
    if (check_string(read_block(fd)) == 0)
        printf("error\n");
    else
        printf("ok\n");
}
