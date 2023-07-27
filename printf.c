#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include "main.h"

int _printf (const char *str, ...)
{
  int it1 = 0;
  int it2 = 0;
  int it_s = 0;
  char cajita[2048];

va_list lista;
va_start(lista, str);

  while (str[it1] != '\0')
    {
        if (str[it1] == '%')
            {
                it1++;
                if (str[it1] == 'c')
                {
                    cajita[it2] = va_arg(lista, int);
                    it1++;
                    it2++;
                }
                else if (str[it1] == 's')
                {
                    char *caso_s = va_arg(lista, char *);
                    while (caso_s[it_s] != '\0')
                    {
                        cajita[it2] = caso_s[it_s];
                        it2++;
                        it_s++;
                    }
                    if (str[it1++] == '\0')
                    cajita[it2] = '\0';
                }
            }
        else
        {
        cajita[it2] = str[it1];
        it1++;
        it2++;
        }
    }
    write (1, cajita, it2);
    va_end(lista);
    return (0);
}
