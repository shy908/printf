#include <stdarg.h>

int my_printf(const char *format, ...){

    // va_list - type to hold information about variable arguments
    // va_start - initialize a variable argument list
    // va_arg - retrieve next argument
    // va_end - end using variable argument list  

    va_list args; // get list of arguments
    va_start(args, format); // init variable argument list

    int i = 0; // iterator
    while (format[i]){
        if(format[i] == '%'){
            i++;
            switch(format[i]){
                // integer data type
                case 'd':
                {
                    int x = va_arg(args, int);
                    putchar(x);
                    break;
                }
                // double/float data type
                case 'f':
                {
                    double x = va_arg(args, double);
                    putchar(x);
                    break;
                }
                // string data type
                case 's':
                {
                    char *x = va_arg(args, char*);
                    putchar(x);
                    break;
                }
                // %
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar(format[i]);
                    break;
            }
        }else{
            putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return 0;
}