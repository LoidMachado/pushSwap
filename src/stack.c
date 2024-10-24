/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:03:33 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:18 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	process_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*target;

	while (*b)
	{
		cheapest = stack_cheapest_element(a, b);
		target = target_element(cheapest, a);
		move_cheapest_and_target(a, b, cheapest, target);
		pa(a, b);
	}
}

void	move_cheapest_and_target(t_stack **a, t_stack **b, t_stack *cheapest,
		t_stack *target)
{
	if ((pos_element(target, *a) == 0 && pos_element(cheapest, *b) == 0))
	{
		while (cheapest != *b && target != *a)
		{
			rr(a, b);
		}
	}
	else if (pos_element(target, *a) && pos_element(cheapest, *b))
	{
		while (cheapest != *b && target != *a)
		{
			rrr(a, b);
		}
	}
	adjust_positions(b, cheapest);
	adjust_positions_a(a, target);
}

void	adjust_positions(t_stack **b, t_stack *cheapest)
{
	if (pos_element(cheapest, *b) == 0)
	{
		while (cheapest != *b)
		{
			rb(b);
		}
	}
	else if (pos_element(cheapest, *b) == 1)
	{
		while (cheapest != *b)
		{
			rrb(b);
		}
	}
}

void	adjust_positions_a(t_stack **a, t_stack *target)
{
	if (pos_element(target, *a) == 0)
	{
		while (target != *a)
		{
			ra(a);
		}
	}
	else if (pos_element(target, *a) == 1)
	{
		while (target != *a)
		{
			rra(a);
		}
	}
}

void	stacks(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
		pb(a, b);
	order_element_a(a);
	process_b(a, b);
	topo_stack_a(a);
	ft_lstfree(*a);
}
