/*
** malloc.h for Malloc in /home/wurmel/rendu/PSU_2016_malloc
** 
** Made by Arnaud WURMEL
** Login   <wurmel_a@epitech.net>
** 
** Started on  Mon Jan 23 16:33:13 2017 Arnaud WURMEL
** Last update Wed Feb  8 20:30:08 2017 Arnaud WURMEL
*/

#ifndef MALLOC_H_
# define MALLOC_H_

typedef struct	s_heap
{
  size_t	block_size;
  int		is_free;
  void		*addr;
  struct s_heap	*prev;
  struct s_heap	*next;
}		t_heap;

void	*malloc(size_t);
void	free(void *);
int	my_printf(const char *, ...);
t_heap	*get_heap(int, t_heap *);
int	extend_heap(t_heap **, size_t, t_heap *);
void	*find_unallocated_block(size_t, t_heap **);
void	show_alloc_mem(void);
void	*realloc(void *, size_t);
void	free_addr_founded(t_heap *);
t_heap	*get_heap_by_address(void *);
char	split_block(t_heap *, size_t);

#endif /* !MALLOC_H_ */
