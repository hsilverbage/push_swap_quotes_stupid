#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;


	if (argc < 2)
		return (0);
	if (ft_check_input(argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (0);
	}

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = NULL;


	ft_create_list(argc, argv, stack_a);

	printf("head of the list is : %d \n", stack_a->head->data);

	t_element	*temp;

	temp = stack_a->head;
	while (temp != NULL)
	{
		ft_printf("%d", temp->data);
		temp = temp->next;
	}

	ft_free_stack_a(stack_a);

	ft_printf("\n");

	return (0);
}
