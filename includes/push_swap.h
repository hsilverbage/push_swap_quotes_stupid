/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:36 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/04 17:33:36 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_element
{
	int					data;
	int					index;
	struct s_element	*next;
}				t_element;

typedef struct s_stack
{
	t_element	*head;
	int			max;
	int			min;
	int			size;
}				t_stack;

t_element	*ft_new_node(char **argv, int i);

int			ft_check_input(int argc, char **argv);
int			ft_check_if_sorted(t_stack *stack_a);

void		ft_create_list(int argc, char **argv, t_stack *stack_a);
void		ft_free_stack(t_stack *stack);
void		ft_rotate(t_stack *stack, char c);
void		ft_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void		ft_swap(t_stack *stack, char c);
void		ft_swap_a_and_b(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse(t_stack *stack, char c);
void		ft_reverse_a_and_b(t_stack *stack_a, t_stack *stack_b);
void		ft_push_a(t_stack *stack_a, t_stack *stack_b);
void		ft_push_b(t_stack *stack_a, t_stack *stack_b);
void		ft_small_sort(int argc, t_stack *stack_a, t_stack *stack_b);
void		ft_radix(t_stack *stack_a, t_stack *stack_b);

/*----------------------------UTILS--------------------------------*/

void		ft_bzero(void *s, size_t n);

int			ft_printf(const char *str, ...);
int			ft_format(va_list args, char c);
int			ft_print_address(void *address);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr_hexa(char *base, unsigned int nbr);
int			ft_putnbr(int nbr);
int			ft_putnbr_unsigned(unsigned int nbr);

long		ft_atol(const char *str);

#endif
