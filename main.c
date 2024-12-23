#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
// Variadic function to print different types of values
// void print_values(const char *format, ...) {
//     va_list args;
//     va_start(args, format);

//     while (*format)
//     {
//         if (*format == 'd') {
//             int num = va_arg(args, int);
//             printf("%d ", num);
//         } else if (*format == 'c')
//         {
//             char c = va_arg(args, int);
//             printf("%c ", c);
//         } else if (*format == 's') {
//             char *str = va_arg(args, char *);
//             printf("%s ", str);
//         }
//         format++;
//     }

//     va_end(args);
//     printf("\n");
// }
// void print_num(char count, ...)
// {
//     va_list args;
//     va_start(args, count);
//     char s = 'a';
//     while (s < count)
//     {
//         int c = va_arg(args, char);
//         printf("%c", c);
//         s++;
//     }
//     va_end(args);
// }
int main()
{
    char c = 'a';
     int a = 323424;
    int b = -10;
    int f = 89;
    char *s = "hello";
    int *p = &a;
    // ft_printf("%c\n", c);
    // int z = ft_printf("%d , %d, %d\n", a , f, a);
    // printf("%d \n", z);
    // ft_printf("%p\n", p);
    // int n  = printf("%X\n", a);
    // printf("%d", n);
    //ft_printf("%x\n", a);
    int fd = ft_printf("%c", 97);
    //printf("\n%d", fd);
    return 0;
}
