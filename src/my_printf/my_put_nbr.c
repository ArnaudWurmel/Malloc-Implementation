/*
** my_put_nbr.c for  in /home/wurmel_a/rendu/Piscine_C_J03
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Wed Sep 30 18:14:59 2015 Arnaud WURMEL
** Last update Thu Nov 12 17:49:10 2015 Arnaud WURMEL
*/

#include "func.h"

int	my_nbr_len(int nb)
{
  int	i;
  int	k;

  k = 0;
  i = 1;
  if (nb < 0)
    k = k + 1;
  while (i != 0 && (nb / i) != 0)
    {
      i = i * 10;
      k = k + 1;
    }
  return (k);
}

void	my_put_nbr_go(int nb)
{
 if (nb > 9)
    {
      my_put_nbr_go(nb / 10);
      my_put_nbr_go(nb % 10);
    }
 else
   my_putchar(nb + '0');
}

void	my_put_nbr(int nb)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return ;
    }
  if (nb < 0)
    {
      nb = nb * (- 1);
      my_putchar('-');
    }
  my_put_nbr_go(nb);
}
