/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_rave_repeat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:38:25 by marcos            #+#    #+#             */
/*   Updated: 2026/04/11 19:23:17 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	define_and_take_first_fork(t_philosopher *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->left->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time,
			philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->right->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time,
			philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time,
			philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->left->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time,
			philo->id, "has taken a fork");
	}
}

void	philo_eat(t_philosopher *philo)
{
	define_and_take_first_fork(philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_now();
	philo->count_meal++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_action(philo->table, get_time_now() - philo->table->start_time,
		philo->id, "is eating");
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left->lock);
	pthread_mutex_unlock(&philo->right->lock);
}

void	philo_sleep(t_philosopher *philo)
{
	print_action(philo->table, get_time_now() - philo->table->start_time,
		philo->id, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	philo_think(t_philosopher *philo)
{
	print_action(philo->table, get_time_now() - philo->table->start_time,
		philo->id, "is thinking");
	usleep(1000);
}
