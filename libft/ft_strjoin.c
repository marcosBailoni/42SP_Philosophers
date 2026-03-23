/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:51:35 by maralves          #+#    #+#             */
/*   Updated: 2025/08/06 18:17:29 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		count1;
	int		count2;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char)
			* ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new)
		return (NULL);
	count1 = 0;
	count2 = 0;
	while (s1[count1])
	{
		new[count1] = s1[count1];
		count1++;
	}
	while (s2[count2])
	{
		new[count1] = s2[count2];
		count1++;
		count2++;
	}
	new[count1] = '\0';
	return (new);
}
