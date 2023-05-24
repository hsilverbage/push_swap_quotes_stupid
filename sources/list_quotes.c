/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:03:41 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/24 20:04:56 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*ft_new_node_quotes(char **tab)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->data = ft_atol(tab[0]);
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_fill_stack_a_quotes(int argc, char **tab, t_stack *stack_a)
{
	t_element	*new;
	int			i;

	new = stack_a->head;
	i = 1;
	while (i < argc)
	{
		new->next = ft_new_node(tab, i);
		new = new->next;
		if (new->data > stack_a->max)
			stack_a->max = new->data;
		if (new->data < stack_a->min)
			stack_a->min = new->data;
		i++;
		new->next = NULL;
	}
}

void	ft_set_index_quotes(t_stack *stack_a)
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

void	ft_create_list_quotes(int argc, char **tab, t_stack *stack_a)
{
	t_element	*new;

	new = ft_new_node_quotes(tab);
	stack_a->head = new;
	stack_a->max = new->data;
	stack_a->min = new->data;
	stack_a->size = argc;
	ft_fill_stack_a_quotes(argc, tab, stack_a);
	ft_set_index_quotes(stack_a);
}
