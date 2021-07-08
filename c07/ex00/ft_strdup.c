#include <stdlib.h>

char *ft_strdup(char *src)
{
    int i;
    char *dest;
    
    i = 0;
    while (src[i])
        i++;

    if ((dest = (char *)malloc((i + 1)*sizeof(char))) == NULL)
        return (0);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

#include <stdio.h>
int main()
{
    char str [] = "Nath";
    char *copied = ft_strdup(str);

    while (*copied)
    {
        printf("%c", *copied);
        copied++;
    }
    free (copied);

    return (0);
}
