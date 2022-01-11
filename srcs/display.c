/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:25:15 by cgoncalv          #+#    #+#             */
/*   Updated: 2022/01/11 11:35:13 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	display_message(t_philo *philo, const char *message, t_bool is_end)
{
	long int		ms;

	pthread_mutex_lock(&philo->db->display_mutex);
	if ((philo->db->can_write == True && !philo->db->stop) || is_end == True)
	{
		if (is_end == True)
			philo->db->can_write = False;
		ms = now() - philo->db->start_time;
		printf("[%ld]\tPhilo %d\t\t%s\n", ms, philo->id, message);
	}
	pthread_mutex_unlock(&philo->db->display_mutex);
}
