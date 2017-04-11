/*
** show_alloc.c for Malloc in /home/wurmel/rendu/PSU_2016_malloc
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Wed Jan 25 12:02:30 2017 Arnaud WURMEL
** Last update Tue Jan 31 10:02:30 2017 Arnaud WURMEL
*/

#include <unistd.h>
#include <stdlib.h>
#include "malloc.h"

void		show_alloc_mem()
{
  t_heap	*heap;

  heap = get_heap(0, NULL);
  my_printf("break : %p\n", sbrk(0));
  while (heap)
    {
      my_printf("Free : %d --- ", heap->is_free);
      my_printf("%p - ", heap->addr);
      my_printf("%p", heap->addr + heap->block_size);
      my_printf(" : %d bytes\n", heap->block_size);
      heap = heap->next;
    }
}
