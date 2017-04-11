/*
** my_putchar.c for  in /home/wurmel/PSU_2015_my_printf
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Fri Nov  6 19:01:38 2015 Arnaud WURMEL
** Last update Sat Nov  7 12:12:01 2015 Arnaud WURMEL
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
