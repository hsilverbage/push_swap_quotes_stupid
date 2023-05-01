/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:39 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/01 17:07:07 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_element	*prev;

	if (stack->head != NULL)
	{
		while (stack->head != NULL)
		{
			prev = stack->head;
			stack->head = stack->head->next;
			free(prev);
		}
		free(stack->head);
	}
	free(stack);
}

t_element	*ft_new_node(char **argv, int i)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->data = ft_atoi(argv[i]);
	new->next = NULL;
	new->index = -1;
	return (new);
}

void	ft_fill_stack_a(int argc, char **argv, t_stack *stack_a)
{
	t_element	*new;
	int	i;

	i = 2;
	while (i < argc)
	{
		new->next = ft_new_node(argv, i);
		new = new->next;
		if (new->data > stack_a->max)
			stack_a->max = new->data;
		if (new->data < stack_a->min)
			stack_a->min = new->data;
		if (new->next == NULL)
			stack_a->last = new;
		i++;
	}
	new = NULL;
}

void	ft_set_index(t_stack *stack_a)
{
	t_element	*temp;
	t_element	*checker;
	int			index;

	temp = stack_a->head;
	index = 1;
	while (index <= stack_a->size)
	{
		while (temp->index != -1)
			temp = temp->next;
		checker = temp->next;
		while (checker != NULL)
		{
			if (checker->data < temp->data && checker->index == -1)
				temp = checker;
			checker = checker->next;
		}
		temp->index = index++;
		temp = stack_a->head;
	}
}

void	ft_create_list(int argc, char **argv, t_stack *stack_a)
{
	t_element	*new;

	new = ft_new_node(argv, 1);
	stack_a->head = new;
	stack_a->max = new->data;
	stack_a->min = new->data;
	ft_fill_stack_a(argc, argv, stack_a);
	stack_a->size = argc - 1;
	ft_set_index(stack_a);
	t_element	*temp = stack_a->head;
	int i = 1;
	while (temp)
	{
		printf("index of %d is %d\n", temp->data, temp->index);
		temp = temp->next;
	}

}
