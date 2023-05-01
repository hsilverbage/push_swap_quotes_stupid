/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:51 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/28 19:27:04 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list(t_stack *stack)
{
	t_element	*temp;

	if(stack->head == NULL)
		return;
	temp = stack->head;
	while (temp != NULL)
	{
		ft_printf("%d", temp->data);
		temp = temp->next;
	}
	ft_printf("\n");
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		return (0);
	if (ft_check_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	ft_create_list(argc, argv, stack_a);
	if (argc < 7 && (ft_check_if_sorted(stack_a) == -1))
		ft_small_sort(argc, stack_a, stack_b);
	//else
	//	ft_radix(stack_a);
	ft_print_list(stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
