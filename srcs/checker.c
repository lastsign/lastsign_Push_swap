/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:35:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/20 22:35:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"

void	check_sorting(t_list **head, t_list **head_b)
{
	t_list	*cur;
	t_list	*prev;

	if (!*head)
		return ;
	if (ft_list_size(*head_b) != 0)
	{
		ft_putendl_fd("KO", 1);
		exit(0);
	}
	cur = (*head)->next;
	prev = *head;
	while (cur)
	{
		if (*(int*)cur->data < *(int*)prev->data)
		{
			ft_putendl_fd("KO", 1);
			exit(0);
		}
		prev = cur;
		cur = cur->next;
	}
	ft_putendl_fd("OK", 1);
}

void	sort_by_commands(t_list **head, t_list **head_b)
{
	char	*line;
	int		size;

	line = NULL;
	if (!*head || *head_b)
		return ;
	while (get_next_line(0, &line) > 0)
	{
		size = ft_strlen(line);
		if (size == 3)
			exec_command_size_three(head, head_b, line, size);
		else if (size == 2)
			exec_command_size_two(head, head_b, line, size);
		else if (size == -1)
			ft_putendl_fd("Error\n", 1);
		free(line);
	}
	ft_putstr_fd(" \b\b \b\b", 1);
	check_sorting(head, head_b);
}

int		main(int argc, char *argv[])
{
	t_list *tmp;
	t_list *head;
	t_list *head_b;

	head = NULL;
	number_of_arguments(&argc, &argv);
	take_all_str(argc, argv, &tmp);
	create_array_value(argc, &head, &head_b, &tmp);
	sort_by_commands(&head, &head_b);
	return (0);
}
