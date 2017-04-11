/*
** realloc.c for  in /home/wurmel/rendu/PSU_2016_malloc
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Wed Jan 25 13:03:20 2017 Arnaud WURMEL
** Last update Wed Feb  8 20:30:19 2017 Arnaud WURMEL
*/

#include <stdlib.h>
#include <string.h>
#include "malloc.h"

void	*calloc(size_t nelem, size_t size)
{
  void	*ptr;

  if ((ptr = malloc(nelem * size)) == NULL)
    return (NULL);
  memset(ptr, 0, size * nelem);
  return (ptr);
}

t_heap		*get_heap_by_address(void *addr)
{
  t_heap	*heap;

  heap = get_heap(0, NULL);
  while (heap)
    {
      if (heap->is_free == 0 && heap->addr == addr)
	return (heap);
      heap = heap->next;
    }
  return (NULL);
}

char		split_block(t_heap *heap, size_t size)
{
  t_heap	*tmp;

  if (size + sizeof(t_heap) < heap->block_size)
    {
      tmp = (t_heap *)(heap->addr + size);
      tmp->block_size = heap->block_size - size - sizeof(t_heap);
      heap->block_size = size;
      tmp->is_free = 1;
      tmp->addr = tmp + 1;
      tmp->prev = heap;
      tmp->next = heap->next;
      heap->next = tmp;
      if (tmp->next)
	tmp->next->prev = tmp;
      return (1);
    }
  return (0);
}
