/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 06:23:20 by marcos            #+#    #+#             */
/*   Updated: 2026/03/22 21:35:10 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "libft/libft.h"

int main (int argc, char **argv)
{
	table table;

	if (!all_input_is_valid_number(argc, argv))
	{
		printf("Error: Invalid input\n");
		return (1);
	}


	return (0);
}