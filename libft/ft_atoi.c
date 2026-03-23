/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:37:14 by maralves          #+#    #+#             */
/*   Updated: 2025/07/30 12:56:50 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned char	*temp_nptr;
	int				number;
	int				sign;

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
