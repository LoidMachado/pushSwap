/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:06:24 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 14:07:24 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_update_index(t_stack *lst)
{
	int				count;
	t_stack			*temp;

	if (lst == NULL)
		return ;
	count = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp->index = count;
		count++;
		temp = temp->next;
	}
}
