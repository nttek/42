#include <stdbool.h>
#include <stdio.h>

int		ft_atoi2(char *str)
{
    int sign;
    int result;

    while(*str == ' ')
        str++;

    sign = 1;
    while(*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }

    result = 0;
    while (*str >= '0' && *str <= '9')
    {
        result *= 10;
        result += *str - '0';
        str++;
    }

    return (result * sign);
}

int main(int argc, char **argv)
{
    printf("%d", ft_atoi2(argv[1]));
    return 0;
}
