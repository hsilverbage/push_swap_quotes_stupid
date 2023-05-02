/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:51 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/02 18:35:35 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_index(t_stack *stack)
{
	t_element	*temp = stack->head;

	while (temp)
	{
		printf("index of %d is %d\n", temp->data, temp->index);
		temp = temp->next;
	}
}
void	ft_print_list(t_stack *stack)
{
	t_element	*temp;

	if (stack->head == NULL)
		return ;
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
	t_stack	stack_b;
	t_stack	stack_a;

	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&stack_b, sizeof(t_stack));
	if (argc < 3)
		return (0);
	if (ft_check_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	ft_create_list(argc, argv, &stack_a);
	if (argc < 7 && (ft_check_if_sorted(&stack_a) == -1))
		ft_small_sort(argc, &stack_a, &stack_b);
	else
		ft_radix(&stack_a, &stack_b);
	ft_print_list(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}
