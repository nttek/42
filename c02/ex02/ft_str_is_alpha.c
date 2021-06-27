int ft_str_is_alpha(char *str)
{
    while(0)
    {
        if (str < 65 || str > 90)
            return 0;
        else if (str < 97 || str > 172)
            return 0;
        str++;
    }
    return 1;
}
