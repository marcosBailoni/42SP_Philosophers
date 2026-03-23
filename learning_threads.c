

// good content to learn

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 06:25:30 by marcos            #+#    #+#             */
/*   Updated: 2026/03/18 09:06:46 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *rotina(void *arg)
{
    int id = *(int *)arg;

    while (1)
    {
        printf("Thread %d trabalhando\n", id);
        usleep(300000);
    }
}

int main()
{
    pthread_t threads[2];
    int ids[2];

    for (int i = 0; i < 2; i++)
    {
        ids[i] = i;
        pthread_create(&threads[i], NULL, rotina, &ids[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}