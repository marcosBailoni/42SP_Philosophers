/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:40:15 by maralves          #+#    #+#             */
/*   Updated: 2026/01/17 01:54:43 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	if (*s != c)
	{
		count++;
		s++;
	}
	while (*s == c)
	{
		s++;
	}
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			count++;
		s++;
	}
	return (count);
}

int	ft_size_word(const char *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

int	ft_free_all_malloc(char **v_arr, int total)
{
	int	count;

	count = 0;
	while (count < total)
	{
		free (v_arr[count]);
		count++;
	}
	free (v_arr);
	return (count);
}

int	ft_alloc_strs(const char *s, char c, char **v_str, size_t total_words)
{
	size_t	index_vect;
	int		word_len;

	index_vect = 0;
	while (index_vect < total_words)
	{
		while (*s == c)
			s++;
		word_len = ft_size_word(s, c);
		v_str[index_vect] = malloc(sizeof(char) * (word_len + 1));
		if (!v_str[index_vect])
		{
			ft_free_all_malloc(v_str, index_vect);
			return (0);
		}
		ft_strlcpy(v_str[index_vect], s, word_len + 1);
		s += word_len;
		index_vect++;
	}
	v_str[index_vect] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**v_str;
	size_t	total_words;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		v_str = malloc(sizeof(char *) * 1);
		if (!v_str)
			return (NULL);
		v_str[0] = NULL;
		return (v_str);
	}
	total_words = ft_count_words(s, c);
	v_str = malloc(sizeof(char *) * (total_words + 1));
	if (!v_str)
		return (NULL);
	if (ft_alloc_strs(s, c, v_str, total_words) == 0)
		return (NULL);
	return (v_str);
}
