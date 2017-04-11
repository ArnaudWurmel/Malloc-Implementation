/*
** my_printf.c for  in /home/wurmel/rendu/PSU_2015_my_printf
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Mon Nov  2 12:51:01 2015 Arnaud WURMEL
** Last update Tue Apr 19 10:36:04 2016 Arnaud WURMEL
*/

#include <unistd.h>
#include <stdarg.h>
#include "func.h"

int	option(char c)
{
  if (c == 'd' || c == 's' || c == 'S' || c == 'p' || c == 'c' || c == 'l' ||
      c == 'b' || c == 'S' || c == 'x' || c == 'X' || c == 'o' || c == 'u' ||
      c == '+' || c == 'i' || c == '#' || c == 'e')
    return (1);
  return (0);
}

int	treatement_three(va_list ap, char format, const char *str, int *i)
{
  int	len;

  len = 0;
  if (format == 'u')
    len = my_putnbr_base((long)va_arg(ap, unsigned int), "0123456789");
  else if (format == '#')
    len = treatement_dieze(ap, str, i);
  else if (format == '+' && str[1] == 'd')
    {
      len = my_putchar('+');
      len = my_putnbr_base((long)va_arg(ap, int), "0123456789") + 1;
      *i = *i + 3;
    }
  else if (format == 'e')
    len = my_put_str_error(va_arg(ap, char *));
  else
    {
      my_putstr("%+");
      len = 2;
      *i = *i + 3;
    }
  return (len);
}

int	treatement_two(va_list ap, char format, const char *str, int *i)
{
  int	len;

  len = 0;
  if (format == 'b')
    len = my_putnbr_base(va_arg(ap, unsigned int), "01");
  else if (format == 'S')
    len = my_putstr_no_printable(va_arg(ap, char *));
  else if (format == 'x')
    len = my_putnbr_base((long)va_arg(ap, int), "0123456789abcdef");
  else if (format == 'X')
    len = my_putnbr_base((long)va_arg(ap, int), "0123456789ABCDEF");
  else if (format == 'o')
    len = my_putnbr_base((long)va_arg(ap, int), "01234567");
  else
    len = treatement_three(ap, format, str, i);
  return (len);
}

int	treatement(va_list ap, char format, const char *str, int *i)
{
  int	len;

  if (format == 'd' || format == 'i')
    {
      len = va_arg(ap, int);
      my_put_nbr(len);
      return (my_nbr_len(len));
    }
  else if (format == 's')
    len = my_putstr(va_arg(ap, char *));
  else if (format == 'c')
    len = my_putchar(va_arg(ap, int));
  else if (format == 'p')
    {
      len = my_putstr("0x");
      len = my_putnbr_base((long)va_arg(ap, void *), "0123456789abcdef") + len;
    }
  else if (format == 'l' && str[1] && str[1] == 'd')
    {
      len = my_putnbr_base(va_arg(ap, long), "0123456789");
      *i = *i + 3;
    }
  else
    len = treatement_two(ap, format, str, i);
  return (len);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
  int		print;

  print = 0;
  i = 0;
  if (format == NULL)
    return (-1);
  va_start(ap, format);
  while (format[i])
    {
      if (format[i] == '%' && format[i + 1] && option(format[i + 1]) == 1)
	print = treatement(ap, format[i + 1], format + i + 1, &i) + print;
      else if (format[i] == '%' && format[i + 1] && format[i + 1] == '%')
	my_putchar('%');
      if (format[i] == '%' && option(format[i + 1]) == 1)
	i = i + 1;
      else
	print = my_putchar(format[i]) + print;
      i = i + 1;
    }
  va_end(ap);
  return (print);
}
