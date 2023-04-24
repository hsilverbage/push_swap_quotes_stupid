/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:30 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/24 19:17:30 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.
rr : ra and rb at the same time.
*/

#include "../includes/push_swap.h"

int	ft_rotate_a(t_stack *stack_a)
{
	t_element	*temp;
	t_element	*first;

	if (!stack_a->head || !stack_a->head->next)
		return (0);
	first = stack_a->head;
	stack_a->head = stack_a->head->next;
	temp = stack_a->head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	stack_a->tail = first;
	temp->next->next = NULL;
	ft_printf("ra\n");
	return (0);
}
// int	ft_rotate_b(t_stack stack_a)
// {



// }

// int	ft_rotate_a_and_b(stack_a)
// {



// }
