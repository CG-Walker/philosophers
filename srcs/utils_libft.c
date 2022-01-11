/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:45:33 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/12/14 01:45:33 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#define SPACES " \t\v\f\r\n"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*s++)
		len++;
	return (len);
}

t_bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (True);
	return (False);
}

static size_t	check_spaces(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && SPACES[j])
	{
		if (str[i] == SPACES[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		ret;
	int		sign;
	size_t	i;

	ret = 0;
	sign = 1;
	i = check_spaces(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (ft_isdigit(str[i]) == False)
		return (-1);
	while (str[i] && ft_isdigit(str[i]) == True)
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (sign * ret);
}
