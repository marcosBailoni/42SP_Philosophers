/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:37:14 by maralves          #+#    #+#             */
/*   Updated: 2026/01/17 01:51:57 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
