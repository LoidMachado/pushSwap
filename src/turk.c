/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:32:52 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:28 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_min(t_stack **a)
{
	t_stack	*elemen_min;
	t_stack	*stack_aux;

	elemen_min = NULL;
	stack_aux = *a;
	while (stack_aux)
	{
		if (!elemen_min || stack_aux->value < elemen_min->value)
			elemen_min = stack_aux;
		stack_aux = stack_aux->next;
	}
	return (elemen_min);
}

t_stack	*stack_max(t_stack **a)
{
	t_stack	*elemen_max;
	t_stack	*stack_aux;

	elemen_max = NULL;
	stack_aux = *a;
	while (stack_aux)
	{
		if (!elemen_max || stack_aux->value > elemen_max->value)
			elemen_max = stack_aux;
		stack_aux = stack_aux->next;
	}
	return (elemen_max);
}

void	topo_stack_a(t_stack **a)
{
	t_stack	*element_min;

	element_min = stack_min(a);
	if (pos_element(element_min, *a) == 0)
	{
		while (element_min != *a)
			ra(a);
	}
	else
	{
		while (element_min != *a)
			rra(a);
	}
}

void	order_element_a(t_stack **a)
{
	t_stack	*max;

	if (ft_lstsize(*a) >= 2)
	{
		max = stack_max(a);
		if (max->index == 0)
			ra(a);
		else if (max->index == 1)
			rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}

int	pos_element(t_stack *element, t_stack *stack)
{
	int	stack_tam;

	stack_tam = ft_lstsize(stack);
	if (element->index <= stack_tam / 2)
		return (0);
	return (1);
}
