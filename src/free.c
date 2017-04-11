/*
** free.c for Malloc in /home/arnaud.wurmel/rendu/PSU_2016_malloc
** 
** Made by Arnaud WURMEL
** Login   <arnaud.wurmel@epitech.net>
** 
** Started on  Wed Feb  8 20:25:17 2017 Arnaud WURMEL
** Last update Wed Feb  8 20:26:35 2017 Arnaud WURMEL
*/

#include <unistd.h>
#include <stdlib.h>
#include "malloc.h"

static void	move_brk()
{
  t_heap	*tmp;
  t_heap	*save;

  tmp = get_heap(0, NULL);
  save = NULL;
  while (tmp)
    {
      if (save == NULL && tmp->is_free)
	save = tmp;
      if (!tmp->is_free)
	save = NULL;
      tmp = tmp->next;
    }
  if (!save)
    return ;
  if (save->prev)
    save->prev->next = NULL;
  if (save->prev == NULL)
    get_heap(1, NULL);
  if (save)
    brk(save);
}

void	free_addr_founded(t_heap *tmp)
{
  tmp->is_free = 1;
  move_brk();
  tmp = get_heap(0, NULL);
  while (tmp && tmp->next)
    {
      if (tmp->is_free && tmp->next->is_free)
	{
	  tmp->block_size += sizeof(t_heap) + tmp->next->block_size;
	  tmp->next = tmp->next->next;
	  if (tmp->next)
	    tmp->next->prev = tmp;
	}
      tmp = tmp->next;
    }
}
