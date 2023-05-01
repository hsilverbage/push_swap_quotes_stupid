/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:01 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/02 00:05:02 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_distance(t_stack *stack_a, int nb)
{
	t_element	*temp;
	int			i;


	i = 1;
	temp = stack_a->head;
	while (temp->index != nb)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_sort_3(t_stack *stack_a)
{
	int max;

	max = ft_find_distance(stack_a, stack_a->size);
	if (max == 1)
		ft_rotate(stack_a, 'a');
	else if (max == 2)
		ft_reverse(stack_a, 'a');
	if (ft_check_if_sorted(stack_a) == -1)
		ft_swap(stack_a, 'a');
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = ft_find_distance(stack_a, 1);
	if (min ==2)
		ft_swap(stack_a, 'a');
	else if (min == 3)
	{
		ft_reverse(stack_a, 'a');
		ft_reverse(stack_a, 'a');
	}
	else if (min == 4)
		ft_reverse(stack_a, 'a');
	ft_push_b(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_push_a(stack_a, stack_b);
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	nb;

	nb = ft_find_distance(stack_a, 2);
	if (nb == 2)
		ft_swap(stack_a, 'a');
	else if (nb != 1)
	{
		while (ft_find_distance(stack_a, 2) != 1)
			ft_reverse(stack_a, 'a');
	}
	ft_push_b(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	if (ft_check_if_sorted(stack_a) == -1)
		ft_swap(stack_a, 'a');
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
