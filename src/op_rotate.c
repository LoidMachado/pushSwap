/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:33:56 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:12 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*topo;
	t_stack	*last;

	if (!stack || !(*stack)->next)
		return ;
	topo = *stack;
	*stack = topo->next;
	last = ft_lstlast(*stack);
	last->next = topo;
	topo->next = NULL;
	ft_update_index(*stack);
}

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
