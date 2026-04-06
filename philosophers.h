/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 05:49:24 by marcos            #+#    #+#             */
/*   Updated: 2026/04/06 00:36:51 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
// #include "libft/libft.h"


#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

//macro para argumentos do input


typedef struct table s_table;

typedef struct fork
{
	int id;
	pthread_mutex_t lock;
} s_fork;

typedef struct philosopher
{
	int id;
	int index;
	int count_meal;
	int	complete_meals;
	long last_meal;
	pthread_mutex_t meal_lock;
	s_fork *left;
	s_fork *right;
	s_table *table;
	pthread_t thread;
	
} s_philosopher;

typedef struct table
{
	int number_of_philos;
	int must_eat_count;

	long time_to_die;
 	long time_to_eat;
 	long time_to_sleep;
	long start_time;

	s_fork *forks;
	s_philosopher *philosophers;

	int running;
	pthread_mutex_t running_lock;
	pthread_mutex_t print_lock;

	int philos_finished;
	pthread_mutex_t finished_lock;

	pthread_t monitor;
 	
} s_table;

//functions

//parse

int total_inputs(int argc);
int input_is_valid_number(int argc, char **argv);
int all_input_is_valid_number(int argc, char **argv);
int	*vect_input(int argc, char **argv);

//table
s_philosopher *create_philosophers(int number_of_philos, s_table *table);
s_fork *create_forks(int number_of_philos);
void	link_forks(s_fork *forks, s_philosopher *philosophers, int size);
int	fill_table(s_table *table, int *input);

//time
long get_time_now();
void fill_start_time(s_table *table);

//print
void	print_action(s_table *table, long time_stamp, int id, const char *message);

//thread_routine
int	is_simulation_running(s_table *table);
void	*routine(void *arg);
void	start_threads_philo(s_table *table);
void	make_main_wait(s_table *table);

//eat sleep rave repeat
void	philo_eat(s_philosopher *philo);
void	philo_sleep(s_philosopher *philo);
void	philo_think(s_philosopher *philo);

//monitor
void	*monitoring(void *arg);
void	start_monitor(s_table *table);

//aux
int	ft_isdigit(int c);
long long	ft_atoll(const char *nptr);

#endif

