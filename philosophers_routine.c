/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:59:12 by marcos            #+#    #+#             */
/*   Updated: 2026/03/29 15:28:56 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	s_philosopher *philo;
	int keep_going;
	long time_now;

	philo = (s_philosopher *)arg;
	keep_going = 1;
	while (keep_going)
	{
		pthread_mutex_lock(&philo->table->running_lock);
		keep_going = philo->table->running;
		pthread_mutex_unlock(&philo->table->running_lock);

		time_now = get_time_now();
		print_action(philo->table, (time_now - philo->table->start_time), philo->id, "is Running");
		usleep(100000);
	}
	return (NULL);
}

void	start_threads_philo(s_table *table)
{
	int i;

	i = 0;
	while (i < table->number_of_philos)
	{
		pthread_create(&table->philosophers[i].thread, NULL, routine, &table->philosophers[i]);
		i++;
	}
}
void	make_main_wait(s_table *table)
{
	int i;
	
	i = 0;
	while (i < table->number_of_philos)
	{
		pthread_join(table->philosophers[i].thread, NULL);
		i++;
	}
}
