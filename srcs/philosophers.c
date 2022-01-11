/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:16:10 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/14 01:16:10 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	display_message(philo, "has taken a fork on his left", False);
	if (philo->left == philo->right)
	{
		ft_usleep(philo->db->time_to_die + 1, philo);
		return ;
	}
	pthread_mutex_lock(philo->right);
	display_message(philo, "has taken a fork on his right", False);
}

static void	eat(t_philo *philo)
{
	/*
	if (philo->nb_of_meal + 1 >= philo->db->min_meal
		&& philo->db->nb_who_ate_enough + 1
		>= philo->db->nb_of_philosophers)
	{
		philo->db->can_write = True;
		display_message(philo, "is eating", True);
	}
	else */
	display_message(philo, "is eating", False);
	ft_usleep(philo->db->time_to_eat, philo);
	philo->nb_of_meal += 1;
	philo->last_meal_time = now();
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

static void	ft_sleep(t_philo *philo)
{
	display_message(philo, "is sleeping", False);
	ft_usleep(philo->db->time_to_sleep, philo);
}

static void	think(t_philo *philo)
{
	display_message(philo, "is thinking", False);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->db->time_to_sleep, philo);
	while (philo->db->stop != True)
	{
		take_forks(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}
