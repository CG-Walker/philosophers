/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:40:49 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/09/27 15:43:53 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS

typedef struct s_philosopher
{
	int id;
	time_to_die;
	time_to_eat;
	time_to_sleep;
}	t_philosopher;