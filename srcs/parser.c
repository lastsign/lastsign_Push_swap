/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:32:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 16:32:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	number_of_arguments(int *argc, char ***argv)
{
	if (*argc > 1)
	{
		if (*argc == 2)
			*argv = check_argum(argc, *argv);
		else
			check_argums(*argc, *argv);
	}
	else
	{
		ft_putstr_fd("Usage: ", 1);
		ft_putstr_fd(*argv[0], 1);
		ft_putstr_fd(" <numbers>", 1);
		exit(0);
	}
}

void	take_all_str(int argc, char **argv, t_list **tmp)
{
	int		f;
	int		i;

	i = 1;
	if (ft_isdigit(argv[0][1]) || ft_isdigit(argv[0][0]))
		f = 1;
	else
		f = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i - f]) > 11)
			an_exception();
		ft_list_push_back(tmp, ft_strdup(argv[i - f]));
		i++;
	}
}

void	check_duplicates(int argc, long *a, t_list *head)
{
	int		i;
	t_list	*tmp;

	heap_sort(a, argc - 1);
	i = 1;
	while (i < argc - 1)
	{
		if (a[i] == a[i - 1])
			an_exception();
		else
			i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		tmp = head;
		while (tmp)
		{
			if (a[i] == *(int *)tmp->data)
				tmp->in = i;
			tmp = tmp->next;
		}
		i++;
	}
}

void	create_array_value(int argc, t_list **head,
	t_list **head_b, t_list **tmp)
{
	long	*a;
	long	*b;
	int		i;

	a = malloc(sizeof(long) * (argc - 1));
	b = malloc(sizeof(long) * (argc - 1));
	i = 0;
	while (*tmp)
	{
		b[i] = ft_atoi((*tmp)->data);
		if (b[i] > 2147483647 || b[i] < -2147483648)
			an_exception();
		a[i] = b[i];
		free_old_list(head, tmp);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_list_push_back(head, &b[i]);
		i++;
	}
	check_duplicates(argc, a, *head);
	*head_b = NULL;
	free(a);
	free(b);
}
