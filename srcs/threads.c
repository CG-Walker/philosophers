/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:03:14 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/14 01:03:14 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	death_end(t_philo *philo)
{
	philo->db->can_write = True;
	display_message(philo, "died");
	pthread_mutex_lock(&philo->db->display_mutex);
	philo->db->can_write = False;
	philo->db->stop = True;
}

static void	eat_enough_end(t_philo *philo)
{
	u_int64_t	ms;

	philo->db->can_write = False;
	pthread_mutex_lock(&philo->db->display_mutex);
	ms = now() - time_to_ms(philo->db->start_time);
	printf("[%ld]\tEveryone\tate enough", ms);
	philo->db->stop = True;
}

static void	*check_end(void *data)
{
	t_philo			*philo;
	t_bool			ate_enough;

	ate_enough = False;
	philo = (t_philo *)data;
	while (philo->db->stop != True)
	{
		if (!philo->db->stop && !ate_enough && philo->db->min_meal != -1
			&& philo->nb_of_meal >= philo->db->min_meal)
		{
			ate_enough = True;
			philo->db->nb_who_ate_enough += 1;
		}
		if (!philo->db->stop && now() - time_to_ms(philo->last_meal_time)
			>= philo->db->time_to_die)
			death_end(philo);
		if (!philo->db->stop && philo->db->nb_who_ate_enough
			== philo->db->nb_of_philosophers)
			eat_enough_end(philo);
	}
	return (NULL);
}

void	create_philosophers(t_db *db)
{
	int	i;

	i = 0;
	gettimeofday(&db->start_time, NULL);
	while (i < db->nb_of_philosophers)
	{
		db->philos[i].last_meal_time = db->start_time;
		pthread_create(&db->philos[i].thread_main,
			NULL, &routine, &db->philos[i]);
		pthread_create(&db->philos[i].thread_death,
			NULL, &check_end, &db->philos[i]);
		pthread_detach(db->philos[i].thread_death);
		i++;
	}
}
