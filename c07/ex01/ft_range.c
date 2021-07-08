#include <stdlib.h>

int *ft_range(int min, int max)
{
    int i = 0;
    int *int_array;

    int_array = malloc((max - min)*sizeof(int));
    if (min >= max || int_array == NULL)
        return (0);  
    while (min < max)
    {
        int_array[i] = min++;
        i++;
    }
    return int_array;
}

#include <stdio.h>
int main()
{
    int min = 0;
    int max = 9;
    int *ptr = ft_range(min, max);
    while(min < max)
    {
        printf("%d, ", *ptr);
        min++;
        ptr++;
    }

    return (0);
}