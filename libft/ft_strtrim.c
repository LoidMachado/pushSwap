/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:18:59 by lmachado          #+#    #+#             */
/*   Updated: 2024/05/22 00:19:17 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*str;

	if (set == NULL || s1 == NULL)
		return ((char *)s1);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) != NULL && end > start)
		end--;
	size = end - start + 1;
	if (size <= 0)
		return (ft_strdup(""));
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy((void *)str, (void *)&s1[start], size);
	str[size] = '\0';
	return (str);
}
