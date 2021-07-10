#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */
}

char *ft_strdup(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = ft_strdup(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = ft_strdup(defn)) == NULL)
       return NULL;
    return np;
}

char *ft_strdup(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}

/*
    struct s_item {
    int     number;
    char    str[100];
    } item;
    item.number = 5;
    strcpy(item.str,"String less than 100 chars");
*/

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

int main()
{
    char d[28][2][15] = {
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

    char *h[] = {"100", "hundred", "hundred and"};
    char *k[] = {"1000", "thousand", "thousand,"};
    char *m[] = {"1000000", "million", "million,"};
    char *b[] = {"1000000000", "billion", "billion,"};
    char *t[] = {"1000000000000", "trillion", "trillion,"};

    int num = 21;
    char numstr[256];
    itoa(num, numstr, 10);

    int i = 0;
    if (num < 20)
    {
        while (i < 28)
        {
            if (strcmp(numstr, d[i][0]) == 0)
            {
                printf("%s\n", d[i][1]);
                return (0);
            }
            i++;
        }
    }
    if (num < 100)
    {
        int div = num / 10;
        int mod = num % 10;

        if (mod == 0)
        {
            while (i < 28)
            {
                if (strcmp(numstr, d[i][0]) == 0)
                {
                    printf("%s\n", d[i][1]);
                    return (0);
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
                    printf("%s - ", d[i][1]);
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
                    printf("%s\n", d[i][1]);
                    return (0);
                }
                i++;
            }
        }
    }    
    /*if num < 20:
        return d[num]
    if num < 100:
        div_, mod_ = divmod(num, 10)
            if mod_ == 0
                return d[num]   
            return d[div_ * 10] + '-' + d[mod_]
    else:
        if num < k[0]:
            divisor, word1, word2 = h
        elif num < m[0]:
            divisor, word1, word2 = k
        elif num < b[0]:
            divisor, word1, word2 = m
        elif num < t[0]:
            divisor, word1, word2 = b
        else:
            divisor, word1, word2 = t
        div_, mod_ = divmod(num, divisor)
        if mod_ == 0:
            return '{} {}'.format(int2words(div_), word1)
        else:
            return '{} {} {}'.format(int2words(div_), word2, int2words(mod_))
*/
}