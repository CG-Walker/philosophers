/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:58:52 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/23 19:45:41 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	usage(void)
{
	printf("Usage : [nb_of_philos] [time_to_die] [time_to_eat] [time_to_sleep] \
	(Opt : [nb_min_eat])\n");
}

static void	join_and_free_philos(t_db *db)
{
	int		i;

	i = 0;
	while (i < db->nb_of_philosophers)
		pthread_join(db->philos[i++].thread_main, NULL);
	free(db->philos);
	i = 0;
	while (i < db->nb_of_philosophers)
		pthread_mutex_destroy(&db->forks[i++]);
	free(db->forks);
}

int	main(int argc, char *argv[])
{
	t_db	database;

	if (argc < 5 || argc > 6)
	{
		usage();
		return (EXIT_FAILURE);
	}
	memset(&database, 0, sizeof(database));
	if (init(&database, argv) == False)
		return (EXIT_FAILURE);
	create_philosophers(&database);
	join_and_free_philos(&database);
}
