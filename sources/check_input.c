/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:48 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/18 02:42:26 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_if_sorted(t_stack *stack_a)
{
	t_element	*temp;
	t_element	*checker;

	temp = stack_a->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		checker = stack_a->head;
		while (checker != temp)
		{
			if (temp->data < checker->data)
				return (-1);
			checker = checker->next;
		}
	}
	return (0);
}

int	ft_check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (nb == ft_atol(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_only_num(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i][j] == ' ' || (argv[i][j] > 10 && argv[i][j] < 16))
		j++;
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	if (argv[i][j] < '0' || argv[i][j] > '9')
		return (-1);
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	while (argv[i][j] == ' ' || (argv[i][j] > 10 && argv[i][j] < 16))
		j++;
	if (argv[i][j] != '\0')
		return (-1);
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		if (ft_check_only_num(argv, i) == -1)
			return (-1);
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (-1);
		if (ft_check_duplicates(argc, argv) == -1)
			return (-1);
		i++;
	}
	return (0);
}
