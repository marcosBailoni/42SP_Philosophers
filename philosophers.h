/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 05:49:24 by marcos            #+#    #+#             */
/*   Updated: 2026/03/21 15:43:36 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

//macro para argumentos do input


typedef struct table table;

typedef struct fork
{
	int id;
	int index;
	pthread_mutex_t lock;
} fork;

typedef struct philosopher
{
	int id;
	int count_meal;
	long last_meal;
	pthread_mutex_t meal_lock;
	fork *left;
	fork *right;
	table *table;
	pthread_t thread;

} philosopher;

typedef struct table
{
	int number_of_philos;
	int must_eat_count;

	long time_to_die;
 	long time_to_eat;
 	long time_to_sleep;
	long start_time;

	fork *forks;
	philosopher *philosophers;

	int running;
	pthread_mutex_t running_lock;
	pthread_mutex_t print_lock;

	int philos_finished;
	pthread_mutex_t finished_lock;
 	
} table;


#endif