/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:43:59 by marcos            #+#    #+#             */
/*   Updated: 2026/03/23 06:10:57 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

philosopher *create_philosophers(int number_of_philos, table *table)
{
	int i;
	philosopher *philosophers;

	philosophers = malloc(sizeof(philosopher) * number_of_philos);
	if (!philosophers)
		return (NULL);
	
	i = 0;
	while (i < number_of_philos)
	{
		philosophers[i].id = i + 1;
		philosophers[i].count_meal = 0;
		philosophers[i].last_meal = 0;
		pthread_mutex_init(&philosophers[i].meal_lock, NULL);
		philosophers[i].table = table;
		i++;
	}
	return (philosophers);
}

fork *create_forks(int number_of_philos)
{
	fork *forks;
	int i;

	forks = malloc(sizeof(fork) * number_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < number_of_philos)
	{
		forks[i].id = i + 1;
		forks[i].index = i;
		pthread_mutex_init(&forks[i].lock, NULL);
		i++;
	}
	return (forks);
}


int	fill_table(table *table, int *input)
{
	table->number_of_philos = input[0];
	table->time_to_die = input[1];
	table->time_to_eat = input[2];
	table->time_to_sleep = input[3];
	table->must_eat_count = input[4];
	table->running = 1;
	table->philos_finished = 0;
	table->philosophers	= create_philosophers(table->number_of_philos, table);
	if (!table->philosophers)
		return (0);
	table->forks = create_forks(table->number_of_philos);
	if (!table->forks)
	{
		free(table->philosophers);
		table->philosophers = NULL;
		return (0);
	}		
	pthread_mutex_init(&table->running_lock, NULL);
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->finished_lock, NULL);
	return (1);
}
