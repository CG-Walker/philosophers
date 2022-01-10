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

long int	time_to_ms(struct timeval time)
{
	long int	ms;

	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

long int	now(void)
{
	long int		time;
	struct timeval	now;

	time = 0;
	if (gettimeofday(&now, NULL) == -1)
	{
		printf("gettimeday error.\n");
		exit(-1);
	}
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
