/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:42:35 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:15 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*aux;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	aux = first->next;
	first->next = aux->next;
	aux->next = first;
	*stack = aux;
	ft_update_index(*stack);
}

void	sa(t_stack **stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
