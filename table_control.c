/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:43:59 by marcos            #+#    #+#             */
/*   Updated: 2026/04/11 19:55:15 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher	*create_philosophers(int number_of_philos, t_table *table)
{
	int				i;
	t_philosopher	*philosophers;

	philosophers = malloc(sizeof(t_philosopher) * number_of_philos);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < number_of_philos)
	{
		philosophers[i].index = i;
		philosophers[i].id = i + 1;
		philosophers[i].count_meal = 0;
		philosophers[i].complete_meals = 0;
		pthread_mutex_init(&philosophers[i].meal_lock, NULL);
		philosophers[i].table = table;
		i++;
	}
	return (philosophers);
}

t_fork	*create_forks(int number_of_philos)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * number_of_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < number_of_philos)
	{
		forks[i].id = i + 1;
		pthread_mutex_init(&forks[i].lock, NULL);
		i++;
	}
	return (forks);
}

void	link_forks(t_fork *forks, t_philosopher *philosophers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		philosophers[i].left = &forks[i];
		philosophers[i].right = &forks[(i + 1) % size];
		i++;
	}
}

int	fill_table(t_table *table, int *input)
{
	table->number_of_philos = input[0];
	table->time_to_die = input[1];
	table->time_to_eat = input[2];
	table->time_to_sleep = input[3];
	table->must_eat_count = input[4];
	table->running = 1;
	table->philos_finished = 0;
	table->philosophers = create_philosophers(table->number_of_philos, table);
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
	link_forks(table->forks, table->philosophers, table->number_of_philos);
	return (1);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philos)
	{
		pthread_mutex_destroy(&table->forks[i].lock);
		pthread_mutex_destroy(&table->philosophers[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->running_lock);
	pthread_mutex_destroy(&table->finished_lock);
	free (table->forks);
	free (table->philosophers);
}
