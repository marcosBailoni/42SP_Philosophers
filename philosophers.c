/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 06:23:20 by marcos            #+#    #+#             */
/*   Updated: 2026/04/05 02:09:34 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **argv)
{
	int *input;
	s_table t;

	if (!all_input_is_valid_number(argc, argv))
	{
		printf("Error: Invalid input\n");
		return (1);
	}
	input = vect_input(argc, argv);
	if (!input)
		return (1);
	if(!fill_table(&t, input))
	{
		free (input);
		return (1);
	}
	free (input);

	fill_start_time(&t);

	start_threads_philo(&t);

	start_monitor(&t);

	make_main_wait(&t);
	
	return (0);
}
