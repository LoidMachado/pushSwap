/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:33:21 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:32 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*last_value_stack(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

t_stack	*last_value_prev(t_stack *stack)
{
	t_stack	*last_prev;

	last_prev = stack;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	return (last_prev);
}

static int	*initialize_numbers(int size)
{
	return (malloc(sizeof(int) * size));
}

static void	process_split(char **split, int *numbers, int *n, int *size)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (verify_int(split[j]) == 0)
		{
			free(numbers);
			free_array(split, ft_arraylen(split));
			ft_error();
		}
		numbers[(*n)++] = atoi(split[j++]);
		(*size)++;
	}
}

int	*convert_args(int ac, char **av, int *size)
{
	int		i;
	int		*numbers;
	int		n;
	char	**split;

	i = 1;
	numbers = initialize_numbers(1000);
	n = 0;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		process_split(split, numbers, &n, size);
		i++;
		free_array(split, ft_arraylen(split));
	}
	return (numbers);
}
