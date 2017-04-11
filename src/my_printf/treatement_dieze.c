/*
** treatement_dieze.c for  in /home/wurmel_a/rendu/PSU_2015_my_printf
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Sun Nov 15 16:58:09 2015 Arnaud WURMEL
** Last update Tue Apr 19 10:33:13 2016 Arnaud WURMEL
*/

#include <stdarg.h>
#include "func.h"

int	flag_d(int nb)
{
  my_put_nbr(nb);
  return (my_nbr_len(nb));
}

int	no_arg_()
{
  my_putchar('%');
  my_putchar('#');
  return (2);
}

int	treatement_dieze(va_list ap, const char *str, int *i)
{
  *i = *i + 3;
  if (str[1] == 'o')
    {
      my_putchar('0');
      return (my_putnbr_base((long)va_arg(ap, int), "01234567") + 1);
    }
  else if (str[1] == 'x')
    {
      my_putstr("0x");
      return (my_putnbr_base((long)va_arg(ap, int), "0123456789abcdef") + 2);
    }
  else if (str[1] == 'd' || str[1] == 'i')
    return (flag_d(va_arg(ap, int)));
  else if (str[1] == 'u')
    return (my_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
  else if (str[1] == 'X')
    {
      my_putstr("0x");
      return (my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF") + 2);
    }
  else if (str[1] == 's')
    return (my_putstr(va_arg(ap, char *)));
  return (no_arg_());
}
