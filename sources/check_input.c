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
	while (argv[i][j] > '0' && argv[i][j] < '9')
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
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (-1);
		if (ft_check_duplicates(argc, argv) == -1)
			return (-1);
		i++;
	}
	return (0);
}
