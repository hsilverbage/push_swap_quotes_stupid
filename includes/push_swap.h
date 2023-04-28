/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:36 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/28 19:05:59 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

#include "../library/lib_push_swap.h"

typedef	struct	s_element
{
	int					data;
	// int				index;
	struct s_element	*next;
}				t_element;

typedef	struct	s_stack
{
	t_element	*head;
	t_element	*last;
	int			max;
	int			min;
	int			size;
}				t_stack;

int	ft_check_input(int argc, char **argv);
int	ft_check_if_sorted(t_stack *stack_a);

t_element	*ft_new_node(char **argv, int i);

void	ft_create_list(int argc, char **argv, t_stack *stack_a);

void	ft_free_stack(t_stack *stack);

void	ft_rotate(t_stack *stack, char c);
void	ft_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);

void	ft_swap(t_stack *stack, char c);
void	ft_swap_a_and_b(t_stack *stack_a, t_stack *stack_b);

void	ft_reverse(t_stack *stack, char c);
void	ft_reverse_a_and_b(t_stack *stack_a, t_stack *stack_b);

void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_a, t_stack *stack_b);

void	ft_small_sort(int argc, t_stack *stack_a);


#endif
