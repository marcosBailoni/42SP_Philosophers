/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_rave_repeat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralves <maralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:38:25 by marcos            #+#    #+#             */
/*   Updated: 2026/04/06 20:23:16 by maralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(s_philosopher *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->left->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->right->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->left->lock);
		print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "has taken a fork");
	}
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_now();
	philo->count_meal++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "is eating");
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left->lock);
	pthread_mutex_unlock(&philo->right->lock);
}

void	philo_sleep(s_philosopher *philo)
{
	print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	philo_think(s_philosopher *philo)
{
	print_action(philo->table, get_time_now() - philo->table->start_time, philo->id, "is thinking");
	usleep(1000);
}
