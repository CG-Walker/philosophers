/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:40:49 by cgoncalv          #+#    #+#             */
/*   Updated: 2022/01/10 20:40:17 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_bool
{
	False,
	True
}	t_bool;

typedef struct s_philo
{
	int				id;
	long int		last_meal_time;
	int				nb_of_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread_main;
	pthread_t		thread_death;
	struct s_db		*db;
}	t_philo;

typedef struct s_db
{
	int				nb_of_philosophers;
	int				nb_who_ate_enough;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_meal;
	struct timeval	start_time;
	t_bool			stop;
	t_bool			can_write;
	pthread_mutex_t	display_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_db;

/* 
** philosophers.c
*/

t_bool		init(t_db *database, char *argv[]);

/* 
**	errors.c
*/

t_bool		display_error(char const *s);

/* 
** threads.c
*/

void		create_philosophers(t_db *db);
void		*check_death(void *data);

/* 
** philosophers.c
*/

void		*routine(void *argv);

/* 
** utils.c
*/

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		ft_usleep(int64_t time_in_ms, t_philo *philo);
long int	now(void);

/* 
** display.c
*/

void		display_message(t_philo *philo, const char *message);
long int	time_to_ms(struct timeval time);

#endif