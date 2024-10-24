/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:32:22 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:05 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*topo;

	if (!a)
		return ;
	topo = *a;
	*a = topo->next;
	topo->next = *b;
	*b = topo;
	ft_update_index(*a);
	ft_update_index(*b);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}
