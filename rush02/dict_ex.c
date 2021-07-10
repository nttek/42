#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

char *int2words(int num)
{
    char *buffer;
    char numstr[256];

    int div;
    int mod;

	if ((buffer = (char *)malloc((256) * sizeof(char))) == NULL)
		return (0);

    itoa(num, numstr, 10);
    static const char d[28][2][15] = {
            "0", "zero", 
            "1", "one",
            "2", "two", 
            "3", "three", 
            "4", "four", 
            "5", "five",
            "6", "six", 
            "7", "seven", 
            "8", "eight", 
            "9", "nine", 
            "10", "ten",
            "11", "eleven", 
            "12", "twelve", 
            "13", "thirteen", 
            "14", "fourteen",
            "15", "fifteen", 
            "16", "sixteen", 
            "17", "seventeen", 
            "18", "eighteen",
            "19", "nineteen", 
            "20", "twenty",
            "30", "thirty", 
            "40", "forty", 
            "50", "fifty", 
            "60", "sixty",
            "70", "seventy", 
            "80", "eighty", 
            "90", "ninety" 
};

    char *h[] = {"hundred", "hundred and"};
    char *k[] = {"thousand", "thousand,"};
    char *m[] = {"million", "million,"};
    char *b[] = {"billion", "billion,"};

    int i = 0;
    if (num < 20)
    {
        while (i < 28)
        {
            if (strcmp(numstr, d[i][0]) == 0)
            {
                strcpy(buffer, d[i][1]);
                return(buffer);
            }
            i++;
        }
    }
    if (num < 100)
    {
        div = num / 10;
        mod = num % 10;

        if (mod == 0)
        {
            while (i < 28)
            {
                if (strcmp(numstr, d[i][0]) == 0)
                {
                    strcpy(buffer, d[i][1]);
                    return(buffer);
                }
                i++;
            }
        }
        else
        {
            char divstr[256];
            itoa(div * 10, divstr, 10);
            i = 0;
            while (i < 28)
            {
                if (strcmp(divstr, d[i][0]) == 0)
                {
                    strcpy(buffer, d[i][1]);
                    break;
                }
                i++;
            }
            i = 0;
            char modstr[256];
            itoa(mod, modstr, 10);
            while (i < 28)
            {
                if (strcmp(modstr, d[i][0]) == 0)
                {
                    strcat(buffer, "-");
                    strcat(buffer, d[i][1]);
                    return (buffer);
                }
                i++;
            }
        }
    } 

    else {
            char        *word1;
            char        *word2;
            long        divisor; //unnecessarily huge

            if (num < 1000)
            {
                divisor = 100;
                word1 = h[0];
                word2 = h[1];
            }
            
            else if (num < 1000000)
            {
                divisor = 1000;
                word1 = k[0];
                word2 = k[1];
            }

            else if (num < 1000000000)
            {
                divisor = 1000000;
                word1 = m[0];
                word2 = m[1];
            }
            
            else
            {
                divisor = 1000000000;
                word1 = b[0];
                word2 = b[1];
            }
   
        div = num / divisor;
        mod = num % divisor;

        if (mod == 0)
        {
            buffer = int2words(div);
            strcat(buffer, " ");
            strcat(buffer, word1);
            return (buffer);
        }
            
        else
        {
            buffer = int2words(div);
            strcat(buffer, " ");
            strcat(buffer, word2);
            strcat(buffer, " ");
            strcat(buffer, int2words(mod));
            return (buffer);
        }
    }   
    return (buffer); //redundant
}

int main()
{
    printf(int2words(2147483647));
}