#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i = 0;
    int *int_array;


    if (min >= max)
    {
        *range = 0;
        return (0); 
    }     
    int_array = malloc((max - min)*sizeof(int));
    if (int_array == NULL)
    {
        *range = 0;
        return (-1);
    }    
    *range = int_array;
    while (min < max)
    {
        int_array[i] = min + i;
        i++;
    }

    return (max - min);
}

int main()
{
    return (0);
}