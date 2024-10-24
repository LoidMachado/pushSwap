/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:02:00 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 16:03:39 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(255);
}

int	veritfy_space_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	verify_int(char *str)
{
	char	*nptr;
	long	number;
	int		i;

	i = 0;
	if ((str[i] == '+' && str[i + 1] == '\0') || (str[i] == '-' \
		&& str[i + 1] == '\0'))
		return (0);
	number = ft_strtol(str, &nptr);
	if (number > 2147483647 || number < -2147483648 || *nptr != '\0')
		return (0);
	return (1);
}
