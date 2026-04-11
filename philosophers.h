/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:23:50 by marcos            #+#    #+#             */
/*   Updated: 2026/04/11 19:43:55 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_table	t_table;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philosopher
{
	int				id;
	int				index;
	int				count_meal;
	int				complete_meals;
	long			last_meal;
	pthread_mutex_t	meal_lock;
	t_fork			*left;
	t_fork			*right;
	t_table			*table;
	pthread_t		thread;
}	t_philosopher;

typedef struct s_table
{
	int				number_of_philos;
	int				must_eat_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	t_fork			*forks;
	t_philosopher	*philosophers;
	int				running;
	pthread_mutex_t	running_lock;
	pthread_mutex_t	print_lock;
	int				philos_finished;
	pthread_mutex_t	finished_lock;
	pthread_t		monitor;
}	t_table;

/* parse */
int				total_inputs(int argc);
int				input_is_valid_number(int argc, char **argv);
int				all_input_is_valid_number(int argc, char **argv);
int				*vect_input(int argc, char **argv);

/* table */
t_philosopher	*create_philosophers(int number_of_philos, t_table *table);
t_fork			*create_forks(int number_of_philos);
void			link_forks(t_fork *forks, t_philosopher *philos, int size);
int				fill_table(t_table *table, int *input);
void			free_table(t_table *table);

/* time */
long			get_time_now(void);
void			fill_start_time(t_table *table);

/* print */
void			print_action(t_table *table, long time_stamp, int id,
					const char *message);

/* routine */
int				is_simulation_running(t_table *table);
void			*routine(void *arg);
void			start_threads_philo(t_table *table);
void			make_main_wait(t_table *table);
int				one_philo(t_table *t);

/* actions */
void			philo_eat(t_philosopher *philo);
void			philo_sleep(t_philosopher *philo);
void			philo_think(t_philosopher *philo);

/* monitor */
void			*monitoring(void *arg);
void			start_monitor(t_table *table);

/* utils */
int				ft_isdigit(int c);
long long		ft_atoll(const char *nptr);

#endif
