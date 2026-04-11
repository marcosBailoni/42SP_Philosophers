/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:31:27 by marcos            #+#    #+#             */
/*   Updated: 2026/04/11 19:41:14 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*case_philo_dead(t_table *table, int i)
{
	pthread_mutex_lock(&table->running_lock);
	table->running = 0;
	pthread_mutex_unlock(&table->running_lock);
	pthread_mutex_lock(&table->print_lock);
	printf("%ld %d died\n", get_time_now() - table->start_time,
		table->philosophers[i].id);
	pthread_mutex_unlock(&table->print_lock);
	pthread_mutex_unlock(&table->philosophers[i].meal_lock);
	return (NULL);
}

void	case_philo_satisfied(t_table *table, int i, int	*philos_satisfied)
{
	if (table->philosophers[i].count_meal >= table->must_eat_count)
	{
		if (table->philosophers[i].complete_meals == 0)
			(*philos_satisfied)++;
		table->philosophers[i].complete_meals = 1;
	}
}

void	*case_all_philo_satisfied(t_table *table)
{
	pthread_mutex_lock(&table->running_lock);
	table->running = 0;
	pthread_mutex_lock(&table->print_lock);
	printf("all ate\n");
	pthread_mutex_unlock(&table->print_lock);
	pthread_mutex_unlock(&table->running_lock);
	return (NULL);
}

void	*monitoring(void *arg)
{
	int		i;
	int		philos_satisfied;
	t_table	*table;

	table = (t_table *) arg;
	philos_satisfied = 0;
	while (1)
	{
		i = 0;
		while (i < table->number_of_philos)
		{
			pthread_mutex_lock(&table->philosophers[i].meal_lock);
			if (get_time_now() - table->philosophers[i].last_meal
				>= table->time_to_die)
				return (case_philo_dead(table, i));
			if (table->must_eat_count != -1)
				case_philo_satisfied(table, i, &philos_satisfied);
			pthread_mutex_unlock(&table->philosophers[i].meal_lock);
			if (philos_satisfied == table->number_of_philos)
				return (case_all_philo_satisfied(table));
			i++;
		}
		usleep (1000);
	}
	return (NULL);
}

void	start_monitor(t_table *table)
{
	pthread_create(&table->monitor, NULL, monitoring, table);
}
