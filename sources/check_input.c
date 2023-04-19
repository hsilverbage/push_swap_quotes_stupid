#include "../includes/push_swap.h"

int	ft_check_duplicates(int argc, char ** argv)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (nb == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (-1);
		if (ft_check_duplicates(argc, argv) == -1)
			return (-1);
		i++;
	}
	return (0);
}
