/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:10:08 by maralves          #+#    #+#             */
/*   Updated: 2025/08/04 16:42:38 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	chars_to_copy;
	size_t	s_len;

	if (!s)
		return (0);
	chars_to_copy = 0;
	s_len = ft_strlen((char *)s);
	if (start < s_len)
		chars_to_copy = s_len - start;
	if (chars_to_copy > len)
		chars_to_copy = len;
	new = malloc(sizeof(char) * chars_to_copy + 1);
	if (!new)
		return (0);
	if (chars_to_copy == 0)
		new[0] = '\0';
	else
		ft_strlcpy(new, s + start, chars_to_copy + 1);
	return (new);
}
