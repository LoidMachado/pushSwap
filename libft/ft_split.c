/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:55:42 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/18 14:10:50 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*ft_get_word(char const *s, int *i, char c)
{
	int				word_len;
	char			*word;

	word_len = 0;
	while (s[*i + word_len] && s[*i + word_len] != c)
		word_len++;
	word = ft_substr(s, *i, word_len);
	*i += word_len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char				**tab;
	int					i;
	int					j;

	i = 0;
	j = 0;
	tab = (char **)malloc((ft_wdlen(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_get_word(s, &i, c);
			if (!tab[j++])
			{
				free_array(tab, j);
				return (NULL);
			}
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
