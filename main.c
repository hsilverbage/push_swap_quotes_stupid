/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:51 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/04 17:56:04 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_b;
	t_stack	stack_a;

	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&stack_b, sizeof(t_stack));
	if (argc < 2)
		return (0);
	if (ft_check_input(argc, argv) == -1)
		return (ft_putstr_fd("Error\n", 2));
	if (argc < 3)
		return (0);
	ft_create_list(argc, argv, &stack_a);
	if (argc < 7 && (ft_check_if_sorted(&stack_a) == -1))
		ft_small_sort(argc, &stack_a, &stack_b);
	else if (argc > 6 && (ft_check_if_sorted(&stack_a) == -1))
		ft_radix(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
