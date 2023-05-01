/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:01 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/28 19:25:47 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_stack *stack_a)
{
	if (stack_a->last->data == stack_a->max)
		ft_swap(stack_a, 'a');
	else if (stack_a->head->data == stack_a->max)
		ft_rotate(stack_a, 'a');
	else
		ft_reverse(stack_a, 'a');
	if (ft_check_if_sorted(stack_a) == -1)
		ft_swap(stack_a, 'a');
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("head value is %d\n", stack_a->head->data);
	ft_printf("max value is %d\n", stack_a->max);
	ft_printf("min value is %d\n", stack_a->min);

	int min;
	int max;
	int	head;

	head = stack_a->head->data;
	min = stack_a->min;
	max = stack_a->max;

	if (head == min || head == max)
		ft_swap(stack_a, 'a');
	ft_push_b(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_push_a(stack_a, stack_b);
	if (ft_check_if_sorted(stack_a) == -1)
		ft_rotate(stack_a, 'a');
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{



}

void	ft_small_sort(int argc, t_stack *stack_a, t_stack *stack_b)
{
	if (argc == 3)
		ft_swap(stack_a, 'a');
	else if (argc == 4)
		ft_sort_3(stack_a);
	else if (argc == 5)
		ft_sort_4(stack_a, stack_b);
	else
		ft_sort_5(stack_a, stack_b);
}
