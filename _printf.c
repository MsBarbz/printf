#include "main.h"

int _printf(const char *format, ...)
{
	int count=0;
	va_list args;

	if(*format == '\0')
	{
		return (-1);
	}

	va_start (args, format);

	while(*format) 
	{

		if (*format != '%') 
	
		{
			write(1, format, 1);
			count++;

		}
		else
		{
			format ++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
                        	count++;
			}
			else if (*format  == 'c')
                        {
                                char c = va_arg(args, int);
                                write(1, &c, 1);
				count++;
                        }
			else if (*format  == 's')
                        {
				char *str = va_arg(args, char*);
	 			int len = 0;

				while(str[len] != '\0')
					
					len++;
				write(1, str, len);
                                count += len;
                        }
		}
		format++;
	}
	va_end(args);
	return count;
}	
