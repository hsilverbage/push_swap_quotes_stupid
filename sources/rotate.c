/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:30 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/02 18:02:47 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.
rr : ra and rb at the same time.
*/

#include "push_swap.h"

void	ft_rotate(t_stack *stack, char c)
{
	t_element	*temp;
	t_element	*first;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	stack->head = first->next;
	temp = stack->head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'x');
	ft_rotate(stack_b, 'x');
	ft_printf("rr\n");
}
