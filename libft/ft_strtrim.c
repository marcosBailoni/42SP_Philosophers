/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:13:59 by maralves          #+#    #+#             */
/*   Updated: 2025/08/06 18:37:57 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_present(char c, const char *str)
{
	while (*str)
	{
		if ((unsigned char) c == (unsigned char) *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	chars_to_copy;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!char_is_present((char)*s1, set))
			break ;
		s1++;
	}
	chars_to_copy = ft_strlen((char *)s1);
	while (chars_to_copy > 0)
	{
		if (!char_is_present((char)s1[chars_to_copy - 1], set))
			break ;
		chars_to_copy--;
	}
	new = malloc(sizeof(char) * chars_to_copy + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, chars_to_copy + 1);
	return (new);
}
