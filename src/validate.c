/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:47:51 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:35 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	number_duplicate(int *number, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (number[i] == number[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verify_order_array(int *number, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (number[i] > number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

long	ft_strtol(char *nptr, char **end_ptr)
{
	int		count;
	int		sign;
	long	result;

	count = 0;
	while (nptr[count] == ' ' || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	sign = 1;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign *= -1;
		count++;
	}
	result = 0;
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		result *= 10;
		result += nptr[count] - '0';
		count++;
	}
	*end_ptr = &nptr[count];
	return (result * sign);
}
