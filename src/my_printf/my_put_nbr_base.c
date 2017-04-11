/*
** my_put_nbr.c for  in /home/wurmel_a/rendu/Piscine_C_J03
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Wed Sep 30 18:14:59 2015 Arnaud WURMEL
** Last update Wed Feb  3 16:07:17 2016 Arnaud WURMEL
*/

#include <stdlib.h>
#include "func.h"

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_putstr_no_printable(char *str)
{
  int	i;
  int	k;

  k = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] >= 127 || str[i] < 32)
	{
	  my_putchar(92);
	  if (str[i] < 8)
	    my_putstr("00");
	  else if (str[i] < 80)
	    my_putchar('0');
	  my_putnbr_base(str[i], "01234567");
	  k = k + 2;
	}
      else
	my_putchar(str[i]);
      k = k + 1;
      i = i + 1;
    }
  return (k);
}

int		my_putnbr_base(unsigned long nbr, char *base)
{
  unsigned int	len;
  unsigned long	i;
  int		j;

  j = 0;
  len = my_strlen(base);
  i = 1;
  while (nbr / i > len - 1 && len > 0)
    i = i * len;
  while (i != 0 && len > 0)
    {
      my_putchar(base[nbr/i]);
      nbr = nbr % i;
      i = i / len;
      j = j + 1;
    }
  return (j);
}
