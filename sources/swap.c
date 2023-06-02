/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:42 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/02 13:55:11 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char c)
{
	t_element	*second;
	t_element	*temp;

	if (!stack->head->next || !stack->head)
		return ;
	second = stack->head->next;
	temp = stack->head;
	stack->head = second;
	temp->next = second->next;
	second->next = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb");
}

void	ft_swap_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 'x');
	ft_swap(stack_b, 'x');
	ft_printf("ss");
}
