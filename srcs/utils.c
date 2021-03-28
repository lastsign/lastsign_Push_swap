/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:57:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/20 22:57:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		ft_numlen(int a)
{
	int	i;

	i = 1;
	while (a / 10)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	an_exception(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

char	**check_argum(int *argc, char **argv)
{
	int j;

	j = 1;
	while (argv[1][j - 1] && argv[1][j])
	{
		if (argv[1][j] == ' ' && argv[1][j - 1] == ' ')
			an_exception();
		j++;
	}
	argv = ft_split(argv[1], ' ');
	j = 0;
	while (argv[j])
		j++;
	*argc = j + 1;
	return (argv);
}

void	check_argums(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][0]) && argv[i][0] != '-')
				an_exception();
			else if (!ft_isdigit(argv[i][j]) && j != 0)
				an_exception();
			else if (!ft_isdigit(argv[i][1]) && argv[i][0] == '-')
				an_exception();
			j++;
		}
		i++;
	}
}

void	free_old_list(t_list **head, t_list **tmp)
{
	free((*tmp)->data);
	free((*tmp)->bonus);
	free((*tmp)->info);
	*head = (*tmp)->next;
	free(*tmp);
	*tmp = *head;
}
