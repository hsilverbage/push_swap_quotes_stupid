/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:07:14 by henrik            #+#    #+#             */
/*   Updated: 2023/05/02 19:36:43 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(t_stack *stack_a)
{
	int	max;
	int	max_bits;

	max_bits = 1;
	max = stack_a->size;
	while (max != 0)
	{
		max = (max >> 1);
		max_bits++;
	}
	return (max_bits);
}

void	ft_radix(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		max_bits;

	i = 0;
	max_bits = ft_get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (((stack_a->head->index >> i) & 1) == 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push_b(stack_a, stack_b);
			j++;
		}
		while (stack_b->head != NULL)
			ft_push_a(stack_a, stack_b);
		i++;
	}
}
