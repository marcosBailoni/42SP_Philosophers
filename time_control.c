/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:14:32 by marcos            #+#    #+#             */
/*   Updated: 2026/03/28 17:35:41 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long get_time_now()
{
	struct timeval tv;
	long time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void fill_start_time(table *table)
{
	int i;
	long time;

	time = get_time_now();
	table->start_time = time;
	i = 0;
	while (i < table->number_of_philos)
	{
		table->philosophers[i].last_meal = time;
		i++;
	}
}