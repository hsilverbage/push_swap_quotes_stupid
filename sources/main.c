/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:51 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/24 19:25:11 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list(t_stack *stack)
{
	t_element	*temp;

	if(stack->head == NULL)
		return;
	temp = stack->head;
	// printf("head of the list is : %d \n", stack->head->data);
	// printf("the tail of stack_a is %d\n", stack_a->tail->data);
	// printf("the size of stack is %d\n", stack->size);
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

	if (argc < 2)
		return (0);
	if (ft_check_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);

	ft_create_list(argc, argv, stack_a);

	ft_print_list(stack_a);
	ft_push_b(stack_a, stack_b);
	ft_print_list(stack_a);
	ft_print_list(stack_b);

	ft_printf("\n");

	return (0);
}
