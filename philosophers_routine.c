/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:59:12 by marcos            #+#    #+#             */
/*   Updated: 2026/04/05 02:10:48 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_simulation_running(s_table *table)
{
	int	result;

	pthread_mutex_lock(&table->running_lock);
	result = table->running;
	pthread_mutex_unlock(&table->running_lock);
	return result;
}

void	*routine(void *arg)
{
	s_philosopher *philo;

	philo = (s_philosopher *)arg;
	while (1)
	{
		if (!is_simulation_running(philo->table))
			break;
		philo_eat(philo);
		if (!is_simulation_running(philo->table))
			break;
		philo_sleep(philo);
		if (!is_simulation_running(philo->table))
			break;
		philo_think(philo);
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
	pthread_join(table->monitor, NULL);
	
}
