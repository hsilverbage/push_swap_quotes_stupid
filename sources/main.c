#include "../includes/push_swap.h"

void	ft_print_list(t_stack *stack_a)
{
	t_element	*temp;

	temp = stack_a->head;
	printf("head of the list is : %d \n", stack_a->head->data);
	while (temp != NULL)
	{
		ft_printf("%d", temp->data);
		temp = temp->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (ft_check_input(argc, argv) == -1)
		return (ft_printf("Error\n"));
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = NULL;

	ft_create_list(argc, argv, stack_a);

	ft_print_list(stack_a);

	ft_free_stack_a(stack_a);

	ft_printf("\n");

	return (0);
}
