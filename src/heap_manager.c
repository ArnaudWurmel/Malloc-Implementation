/*
** heap_manager.c for Malloc in /home/wurmel/rendu/PSU_2016_malloc
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Wed Jan 25 12:02:53 2017 Arnaud WURMEL
** Last update Thu Feb  9 23:18:47 2017 Arnaud WURMEL
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

t_heap		*get_heap(int should_save, t_heap *value)
{
  static t_heap	*heap = NULL;

  if (should_save)
    heap = value;
  return (heap);
}

static void	add_block_to_heap(t_heap **first,
				  t_heap *new,
				  t_heap *to_start)
{
  t_heap	*tmp;

  if (*first == NULL)
    *first = new;
  else
    {
      if (!to_start)
	tmp = *first;
      else
	tmp = to_start;
      while (tmp && tmp->next)
	tmp = tmp->next;
      tmp->next = new;
      new->prev = tmp;
    }
}

int		extend_heap(t_heap **first, size_t size_block, t_heap *to_start)
{
  int		pagesize;
  int		to_alloc;
  int		check;
  t_heap	*new;

  to_alloc = size_block + sizeof(t_heap);
  if ((pagesize = getpagesize()) <= 0)
    return (1);
  to_alloc = ((to_alloc / pagesize) + 1) * pagesize;
  check = to_alloc - size_block - (sizeof(t_heap) * 2);
  if (check <= 0)
    to_alloc += pagesize;
  if ((new = sbrk(to_alloc)) == (void *)-1)
    return (1);
  new->block_size = to_alloc - sizeof(t_heap);
  new->addr = new + 1;
  new->is_free = 1;
  new->next = NULL;
  new->prev = NULL;
  add_block_to_heap(first, new, to_start);
  get_heap(1, *first);
  return (0);
}

static void	*block_fusion(t_heap *tmp, size_t size)
{
  t_heap	*new;

  if ((int)(tmp->block_size - size) > (int)sizeof(t_heap))
    {
      new = (t_heap *)(((void *)tmp) + (tmp->block_size - size));
      new->block_size = size;
      new->is_free = 0;
      new->addr = new + 1;
      new->prev = tmp;
      new->next = tmp->next;
      tmp->next = new;
      tmp->block_size -= (new->block_size + sizeof(t_heap));
      if (new->next)
	new->next->prev = new;
      return (new->addr);
    }
  else if (tmp->block_size == size)
    {
      tmp->is_free = 0;
      return (tmp->addr);
    }
  return (NULL);
}

void		*find_unallocated_block(size_t size, t_heap **last_block)
{
  void		*addr;
  t_heap	*tmp;

  if (*last_block)
    tmp = *last_block;
  else
    tmp = get_heap(0, NULL);
  while (tmp)
    {
      if (tmp->is_free && tmp->block_size >= size)
	{
	  if ((addr = block_fusion(tmp, size)) != NULL)
	    return (addr);
	}
      if (!tmp->next)
	*last_block = tmp;
      tmp = tmp->next;
    }
  return (NULL);
}
