/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:48:24 by marcos            #+#    #+#             */
/*   Updated: 2026/03/21 22:56:19 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include "philosophers.h"

int total_inputs(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	return (0);
}

int input_is_valid_number(int argc, char **argv)
{
	int i;
	int j;

	i = 1;	
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0])
			return (0);
		if (argv[i][0] == '+')
		{
			j++;
			if (!argv[i][j])
				return (0);
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int all_input_is_valid_number(int argc, char **argv)
{
	if (!total_inputs(argc))
		return (0);
	if (!input_is_valid_number(argc, argv))
		return (0);	
	return (1);
}

int	*vect_input(int argc, char **argv)
{
	int *input;
	int i;

	i = 0;
	input = malloc(sizeof(int) * 5);
	if (!input)
		return (NULL);
	input[0] = ft_atoi(argv[1]);
	input[1] = ft_atoi(argv[2]);
	input[2] = ft_atoi(argv[3]);
	input[3] = ft_atoi(argv[4]);
	if (argc == 6)
		input[4] = ft_atoi(argv[5]);
	else
		input[4] = -1;
	while (i < 4)
	{
		if (input[i] <= 0 || (argc == 6 && input[4] <= 0))
		{
			free(input);
			return (NULL);
		}
		i++;
	}
	return (input);
}



// ./philo 
// 		number_of_philos 
// 		time_to_die 
// 		time_to_eat 
// 		time_to_sleep 
// 		[must_eat] -- optional