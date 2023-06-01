/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:24:42 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/01 13:25:15 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = i;
		while (str[i] && (str[i] == ' ' || (str[i] > 10 && str[i] < 16)))
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (i == j)
			return (ft_error("Error\n"));
	}
	if (i == 0)
		ft_error("Error\n");
	return (0);
}

int	ft_check_duplicates_quotes(int max, char **tab)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < max)
	{
		nb = ft_atol(tab[i]);
		j = i + 1;
		while (j < max)
		{
			if (nb == ft_atol(tab[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_all_input_quotes(char *str)
{
	char	**tab;
	long	nb;
	int		i;
	int		j;

	j = 0;
	i = 0;
	nb = 0;
	if (ft_check_num(str) == -1)
		ft_error("Error\n");
	tab = ft_split(str, ' ');
	while (tab[j])
		j++;
	while (tab[i])
	{
		nb = ft_atol(tab[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			ft_error_tab("Error\n", tab);
		if (ft_check_duplicates_quotes(j, tab) == -1)
			ft_error_tab("Error\n", tab);
		i++;
	}
	return (tab);
}
