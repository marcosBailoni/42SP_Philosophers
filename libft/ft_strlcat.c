/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:32:09 by maralves          #+#    #+#             */
/*   Updated: 2025/08/06 18:19:19 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	count = 0;
	while ((len_dest + count + 1) < size && src[count])
	{
		dst[len_dest + count] = src[count];
		count++;
	}
	dst[len_dest + count] = '\0';
	return (len_dest + len_src);
}
