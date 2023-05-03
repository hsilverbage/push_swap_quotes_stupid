/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:22:30 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/03 15:33:54 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	result;
	long	neg;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > INT_MAX)
			return (LONG_MAX);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * neg);
}
