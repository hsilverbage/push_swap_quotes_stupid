/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:51 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/24 20:05:36 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_tab(char *s, char **tab)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	exit (-1);
}

int	ft_error(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	exit (-1);
}

int	ft_new_argc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_for_one_arg(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**tab;

	tab = NULL;
	tab = ft_all_input_quotes(argv[1]);
	ft_create_list_quotes(ft_new_argc(tab), tab, stack_a);
	if (ft_new_argc(tab) < 6)
		ft_small_sort((ft_new_argc(tab) + 1), stack_a, stack_b);
	ft_free_all(tab, ft_new_argc(tab));
}
int	main(int argc, char **argv)
{
	t_stack	stack_b;
	t_stack	stack_a;

	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&stack_b, sizeof(t_stack));
	if (argc < 2)
		return (0);
	if (argc == 2)
		ft_for_one_arg(argv, &stack_a, &stack_b);
	else
	{
		if (ft_check_input(argc, argv) == -1)
			ft_error("Error\n");
		ft_create_list(argc, argv, &stack_a);
		if (argc < 7 && (ft_check_if_sorted(&stack_a) == -1))
			ft_small_sort(argc, &stack_a, &stack_b);
	}
	if ((argc > 6 || argc == 2) && (ft_check_if_sorted(&stack_a) == -1))
		ft_radix(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
