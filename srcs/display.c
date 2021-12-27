/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:25:15 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/14 23:25:15 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	display_message(t_philo *philo, const char *message)
{
	u_int64_t		ms;
	struct timeval	t;

	if (philo->db->can_write == True)
	{
		pthread_mutex_lock(&philo->db->display_mutex);
		gettimeofday(&t, NULL);
		ms = time_to_ms(t) - time_to_ms(philo->db->start_time);
		printf("[%ld]\tPhilo %d\t\t%s\n", ms, philo->id, message);
		pthread_mutex_unlock(&philo->db->display_mutex);
	}
}
