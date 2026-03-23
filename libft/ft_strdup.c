/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:37:35 by maralves          #+#    #+#             */
/*   Updated: 2025/08/04 16:43:52 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp_s;
	char	*new_str;
	int		i;

	i = 0;
	temp_s = (char *)s;
	while (s[i])
	{
		i++;
	}
	new_str = malloc(sizeof(char) * i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (temp_s[i])
	{
		new_str[i] = temp_s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
