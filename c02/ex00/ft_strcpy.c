#include <stdio.h>
char *ft_strcpy(char *dest, char *src)
{
    *dest = *src;
}

int main()
{
    char a [5] = "no";
    char b [2] = "ok";

    printf("%s\n", a);
    ft_strcpy(a, b);
    printf("%s\n", a);
    return(0);
}
