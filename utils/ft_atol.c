/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:22:30 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/02 00:16:26 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_overflow(int neg)
{
	if (neg < 0)
		return (0);
	return (-1);
}

long	ft_atol(const char *str)
{
	size_t		i;
	long int	result;
	int			neg;

	result = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r' \
			|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (result != ((result * 10 + (str[i] - '0')) / 10))
			return (ft_overflow(neg));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= neg;
	return (result);
}