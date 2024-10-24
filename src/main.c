/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:31:22 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:02:38 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_array(char **array, int pos)
{
	while (pos > 0)
		free(array[--pos]);
	free(array);
}

void	verify_empty_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!veritfy_space_empty(av[i]))
			ft_error();
		i++;
	}
}

void	ft_lstfree(t_stack *lst)
{
	t_stack	*temp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void	add_to_stack(t_stack **stack_a, int *numbers, int size)
{
	t_stack	*new_no;
	int		i;

	i = 0;
	while (i < size)
	{
		new_no = ft_lstnew(numbers[i]);
		ft_lstadd_back(stack_a, new_no);
		i++;
	}
	ft_update_index(*stack_a);
	free(numbers);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*args;
	int		size;

	size = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	verify_empty_args(ac, av);
	args = convert_args(ac, av, &size);
	if (number_duplicate(args, size))
	{
		free(args);
		ft_error();
	}
	if (verify_order_array(args, size))
	{
		free(args);
		exit(0);
	}
	add_to_stack(&a, args, size);
	stacks(&a, &b);
	return (0);
}
