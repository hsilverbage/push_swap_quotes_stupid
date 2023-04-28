/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:53 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/28 17:52:53 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
 #include "../includes/push_swap.h"

void	ft_reverse(t_stack *stack, char c)
{
	t_element	*last;
	t_element	*temp;

	last = stack->head;
	while (last->next != NULL)
		last = last->next;
	temp = stack->head;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	last->next = stack->head;
	stack->head = last;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_reverse_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse(stack_a, 'x');
	ft_reverse(stack_b, 'x');

	ft_printf("rrr\n");
}
