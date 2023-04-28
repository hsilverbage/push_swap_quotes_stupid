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

void	ft_sort_4(t_stack *stack_a)
{


}

void	ft_sort_5(t_stack *stack_a)
{



}

void	ft_small_sort(int argc, t_stack *stack_a)
{
	if (argc == 3)
		ft_swap(stack_a, 'a');
	else if (argc == 4)
		ft_sort_3(stack_a);
	else if (argc == 5)
		ft_sort_4(stack_a);
	else
		ft_sort_5(stack_a);
}
