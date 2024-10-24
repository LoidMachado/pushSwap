/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:49:36 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:02 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost(t_stack *element, t_stack **stack)
{
	int	cost;

	cost = ft_lstsize(*stack) - element->index;
	if (pos_element(element, *stack) == 0)
		cost = element->index;
	return (cost);
}

int	cost_total(t_stack *target, t_stack *element_b, t_stack **a, t_stack **b)
{
	int	cost_total;
	int	cost_a;
	int	cost_b;

	cost_a = cost(target, a);
	cost_b = cost(element_b, b);
	cost_total = cost_a + cost_b;
	if ((pos_element(target, *a) == 0 && pos_element(element_b, *b) == 0)
		|| (pos_element(target, *a) && pos_element(element_b, *b)))
	{
		cost_total = cost_b;
		if (cost_a > cost_b)
			cost_total = cost_a;
	}
	return (cost_total);
}

t_stack	*stack_cheapest_element(t_stack **a, t_stack **b)
{
	t_stack				*cheapest_element;
	t_stack				*stack_aux;
	int					cost_total_element;
	int					cost_cheapest;

	cheapest_element = NULL;
	stack_aux = *b;
	while (stack_aux)
	{
		cost_total_element = cost_total(target_element(stack_aux, a), stack_aux,
				a, b);
		if (cheapest_element)
			cost_cheapest = cost_total(target_element(cheapest_element, a),
					cheapest_element, a, b);
		if (!cheapest_element || cost_total_element < cost_cheapest)
			cheapest_element = stack_aux;
		stack_aux = stack_aux->next;
	}
	return (cheapest_element);
}
