/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:31:27 by marcos            #+#    #+#             */
/*   Updated: 2026/04/01 06:40:25 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitoring(void *arg)
{
	s_table *table;
	int		i;
	int		philos_satisfied;

	table = (s_table *)arg;
	while (1)
	{
		i = 0;
		philos_satisfied = 0;
		while (i < table->number_of_philos)
		{
			pthread_mutex_lock(&table->philosophers[i].meal_lock);

			if (get_time_now() - table->philosophers[i].last_meal >= table->time_to_die)
			{
				pthread_mutex_unlock(&table->philosophers[i].meal_lock);

				pthread_mutex_lock(&table->running_lock);
				table->running = 0;
				pthread_mutex_unlock(&table->running_lock);

				pthread_mutex_lock(&table->print_lock);
				printf("%ld %d died\n",
					get_time_now() - table->start_time,
					table->philosophers[i].id);
				pthread_mutex_unlock(&table->print_lock);

				return (NULL);
			}

			if (table->must_eat_count > 0
				&& table->philosophers[i].count_meal >= table->must_eat_count)
				philos_satisfied++;

			pthread_mutex_unlock(&table->philosophers[i].meal_lock);
			i++;
		}

		if (table->must_eat_count > 0
			&& philos_satisfied == table->number_of_philos)
		{
			pthread_mutex_lock(&table->running_lock);
			table->running = 0;
			pthread_mutex_unlock(&table->running_lock);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

// void	*monitoring(void *arg)
// {
// 	s_table *table;
// 	int	i;
// 	int philos_satisfied;

// 	table = (s_table *)arg;
// 	philos_satisfied = 0;
// 	while (1)
// 	{
// 		i = 0;
// 		while(i < table->number_of_philos)
// 		{
// 			pthread_mutex_lock(&table->philosophers[i].meal_lock);
// 			if (get_time_now() - table->philosophers[i].last_meal >= table->time_to_die)
// 			{
// 				pthread_mutex_lock(&table->running_lock);
// 				table->running = 0;
// 				printf("%ld %d dead", get_time_now(), table->philosophers[i].id);
// 				pthread_mutex_unlock(&table->running_lock);		
// 				pthread_mutex_unlock(&table->philosophers[i].meal_lock);		
// 				break;
// 			}
// 			pthread_mutex_unlock(&table->philosophers[i].meal_lock);
// 			if (table->must_eat_count > 0)
// 			{
// 				pthread_mutex_lock(&table->philosophers[i].meal_lock);
// 				if (table->philosophers[i].count_meal == table->must_eat_count)
// 					philos_satisfied++;
// 				pthread_mutex_unlock(&table->philosophers[i].meal_lock);
// 				if (philos_satisfied == table->must_eat_count)
// 					break;
// 			}
// 			i++;
// 		}
// 	}
// }
