/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:02:34 by marcos            #+#    #+#             */
/*   Updated: 2026/03/30 20:17:15 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(s_table *table, long time_stamp, int id, const char *message)
{
	pthread_mutex_lock(&table->running_lock);
	if (table->running)
	{
		pthread_mutex_lock(&table->print_lock);
		printf("%ld %d %s\n", time_stamp, id, message);
		pthread_mutex_unlock(&table->print_lock);
	}

	pthread_mutex_unlock(&table->running_lock);
}
