/*
** func.h for  in /home/wurmel/rendu/PSU_2015_my_printf/include
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Tue Nov  3 21:42:32 2015 Arnaud WURMEL
** Last update Tue Apr 19 10:34:05 2016 Arnaud WURMEL
*/

#ifndef FUNC_H_
# define FUNC_H_
# include <stdarg.h>

void	my_put_nbr(int nb);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_nbr_len(int nb);
int	my_putstr_no_printable(char *str);
int	my_putnbr_base(unsigned long nbr, char *base);
int	treatement_dieze(va_list ap, const char *str, int *i);
int	my_put_str_error(char *str);
int	my_putstr_tetris(char *);

#endif /* !FUNC_H_ */
