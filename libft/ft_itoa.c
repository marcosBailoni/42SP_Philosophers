/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:52:18 by maralves          #+#    #+#             */
/*   Updated: 2025/08/06 17:09:35 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_str_size(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

char	*ft_fill_malloc(char *new, int n, int size)
{
	int	index;
	int	zero_is_filled;

	zero_is_filled = 0;
	if (n == -2147483648)
	{
		ft_strlcpy(new, "-2147483648", size);
		return (new);
	}
	index = size - 2;
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
		zero_is_filled = 1;
	}
	while (index >= zero_is_filled)
	{
		new[index] = n % 10 + '0';
		n = n / 10;
		index--;
	}
	new[size - 1] = '\0';
	return (new);
}

char	*ft_itoa(int n)
{
	int		new_len;
	char	*new;

	new_len = count_str_size(n);
	new = malloc (sizeof(char) * new_len + 1);
	if (!new)
		return (NULL);
	ft_fill_malloc(new, n, new_len + 1);
	return (new);
}
