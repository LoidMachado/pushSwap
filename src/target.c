/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:11:45 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:24 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*target_element(t_stack *element, t_stack **a)
{
	t_stack				*target;
	t_stack				*stack_aux;

	target = NULL;
	stack_aux = *a;
	while (stack_aux)
	{
		if (stack_aux->value > element->value)
		{
			if (!target || stack_aux->value < target->value)
				target = stack_aux;
		}
		stack_aux = stack_aux->next;
	}
	if (!target)
		target = stack_min(a);
	return (target);
}
