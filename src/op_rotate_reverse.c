/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:34:14 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:08 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*last_prev;

	if (!stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last_prev = last_value_prev(*stack);
	last->next = *stack;
	*stack = last;
	last_prev->next = NULL;
	ft_update_index(*stack);
}

void	rra(t_stack **a)
{
	rotate_reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rotate_reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}
