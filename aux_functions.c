/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:37:14 by maralves          #+#    #+#             */
/*   Updated: 2026/04/06 20:23:06 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoll(const char *nptr)
{
	unsigned char			*temp_nptr;
	long long				number;
	long long				sign;

	temp_nptr = (unsigned char *)nptr;
	number = 0;
	sign = 1;
	while (*temp_nptr == ' ' || (*temp_nptr >= 9 && *temp_nptr <= 13))
		temp_nptr++;
	if (*temp_nptr == '-' || *temp_nptr == '+')
	{
		if (*temp_nptr == '-')
			sign = -sign;
		temp_nptr++;
	}
	while (*temp_nptr >= '0' && *temp_nptr <= '9')
	{
		number = number * 10 + (*temp_nptr - '0');
		temp_nptr++;
	}
	return (number * sign);
}
