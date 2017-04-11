/*
** my_putstr.c for  in /home/wurmel/PSU_2015_my_printf
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Fri Nov  6 19:01:52 2015 Arnaud WURMEL
** Last update Tue Apr 19 10:34:18 2016 Arnaud WURMEL
*/

#include <stdlib.h>
#include <unistd.h>
#include "func.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (i);
}

int	my_put_str_error(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
  return (i);
}
