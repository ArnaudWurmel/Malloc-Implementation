/*
** malloc.c for Malloc in /home/wurmel/rendu/PSU_2016_malloc
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Mon Jan 23 16:30:03 2017 Arnaud WURMEL
** Last update Fri Feb 10 11:31:27 2017 Arnaud WURMEL
*/

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

pthread_mutex_t	lock;

void	*my_return(void *value)
{
  pthread_mutex_unlock(&lock);
  return (value);
}

void		*malloc(size_t size)
{
  t_heap	*heap;
  t_heap	*last_block;
  void		*addr;

  pthread_mutex_lock(&lock);
  last_block = NULL;
  heap = get_heap(0, NULL);
  if ((addr = find_unallocated_block(size, &last_block)) == NULL)
    {
      if (extend_heap(&heap, size, last_block) == 1)
	return (my_return(NULL));
      if ((addr = find_unallocated_block(size, &last_block)) == NULL)
	return (my_return(NULL));
    }
  return (my_return(addr));
}

void		*realloc(void *ptr, size_t size)
{
  void		*new;
  t_heap	*heap;

  if (ptr == NULL)
    return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  pthread_mutex_lock(&lock);
  if ((heap = get_heap_by_address(ptr)) == NULL)
    return (my_return(NULL));
  if (split_block(heap, size))
    return (my_return(ptr));
  pthread_mutex_unlock(&lock);
  if ((new = malloc(size)) == NULL)
    return (NULL);
  memcpy(new, ptr, (size > heap->block_size) ? heap->block_size : size);
  free(ptr);
  return (new);
}

void		free(void *ptr)
{
  t_heap	*tmp;

  if (ptr == NULL)
    return ;
  pthread_mutex_lock(&lock);
  tmp = (void *)(ptr - (unsigned long long)sizeof(t_heap));
  if (tmp->addr != ptr || (void *)tmp >= sbrk(0))
    {
      pthread_mutex_unlock(&lock);
      return ;
    }
  free_addr_founded(tmp);
  pthread_mutex_unlock(&lock);
}
