/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_database.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:54:58 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/21 21:54:58 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static t_bool	check_values(t_db *database, t_bool is_there_min_meal)
{
	if (database->nb_of_philosophers < 0)
		return (display_error("Wrong numbers of philosophers.\n"));
	if (database->time_to_die < 0)
		return (display_error("Wrong time to die.\n"));
	if (database->time_to_eat < 0)
		return (display_error("Wrong time to eat.\n"));
	if (database->time_to_sleep < 0)
		return (display_error("Wrong time to sleep.\n"));
	if (is_there_min_meal && database->min_meal < 0)
		return (display_error("Wrong time to sleep.\n"));
	return (True);
}

static t_bool	init_philos(t_db *db)
{
	int	i;

	i = 0;
	db->philos = malloc(sizeof(t_philo) * (db->nb_of_philosophers));
	db->forks = malloc(sizeof(pthread_mutex_t) * (db->nb_of_philosophers));
	if (!db->philos || !db->forks)
	{	
		perror("philosophers:");
		return (False);
	}
	while (i < db->nb_of_philosophers)
	{
		db->philos[i].id = i + 1;
		db->philos[i].nb_of_meal = 0;
		pthread_mutex_init(&db->forks[i], NULL);
		if (i == 0)
			db->philos[i].left = &db->forks[db->nb_of_philosophers - 1];
		else
			db->philos[i].left = &db->forks[i - 1];
		db->philos[i].right = &db->forks[i];
		db->philos[i].db = db;
		i++;
	}
	return (True);
}

void	init_base_values(t_db *db, char *argv[])
{
	db->nb_of_philosophers = ft_atoi(argv[1]);
	db->time_to_die = ft_atoi(argv[2]);
	db->time_to_eat = ft_atoi(argv[3]);
	db->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		db->min_meal = ft_atoi(argv[5]);
	else
		db->min_meal = -1;
	db->nb_who_ate_enough = 0;
	db->stop = False;
	db->can_write = True;
}

t_bool	init(t_db *database, char *argv[])
{
	if (!database)
	{
		perror("philosophers:");
		return (False);
	}
	init_base_values(database, argv);
	if (argv[5])
	{
		if (check_values(database, True) == False
			|| init_philos(database) == False)
			return (False);
	}
	else
		if (check_values(database, False) == False
			|| init_philos(database) == False)
			return (False);
	return (True);
}
