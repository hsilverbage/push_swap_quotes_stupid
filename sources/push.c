/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:26 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/04 17:15:22 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/

#include "push_swap.h"

void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*temp;

	if (stack_b->head == NULL)
		return ;
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_a->head == NULL)
	{
		stack_a->head = temp;
		stack_a->head->next = NULL;
	}
	else
	{
		temp->next = stack_a->head;
		stack_a->head = temp;
	}
	ft_printf("pb\n");
}

void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*temp;

	if (stack_a->head == NULL)
		return ;
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_b->head == NULL)
	{
		stack_b->head = temp;
		stack_b->head->next = NULL;
	}
	else
	{
		temp->next = stack_b->head;
		stack_b->head = temp;
	}
	ft_printf("pb\n");
}
