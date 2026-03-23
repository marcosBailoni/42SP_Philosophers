/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 06:23:20 by marcos            #+#    #+#             */
/*   Updated: 2026/03/23 05:59:34 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "libft/libft.h"

int main (int argc, char **argv)
{
	int *input;
	table t;

	if (!all_input_is_valid_number(argc, argv))
	{
		printf("Error: Invalid input\n");
		return (1);
	}
	input = vect_input(argc, argv);
	if (!input)
		return (1);
	if(fill_table(&t, input))
	{
		free (input);
		return (1);
	}	
	
	free (input);

	return (0);
}