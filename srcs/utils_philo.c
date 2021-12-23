/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:36:39 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/23 19:36:39 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int64_t	time_to_ms(struct timeval time)
{
	int64_t	ms;

	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

int64_t	now(void)
{
	int64_t			time;
	struct timeval	now;

	time = 0;
	gettimeofday(&now, NULL);
	time = time_to_ms(now);
	return (time);
}

void	ft_usleep(int64_t time_in_ms, t_philo *philo)
{
	int64_t	start_time;

	start_time = 0;
	start_time = now();
	while (!philo->db->stop && (now() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
