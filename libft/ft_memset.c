/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:43:15 by maralves          #+#    #+#             */
/*   Updated: 2025/08/04 16:46:51 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			count;

	temp = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*temp = (unsigned char)c;
		temp++;
		count++;
	}
	return (s);
}
