/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:26:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/24 14:26:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"

void	greet_then_prev(t_list **help, t_list **prev_help, t_bonus *bonus)
{
	t_list	*cur;
	t_list	*prev;

	cur = *help;
	prev = *prev_help;
	if (*(int*)cur->data < *(int*)prev->data)
	{
		if (bonus->c == 1)
		{
			ft_putstr_fd(RED, 1);
			ft_putendl_fd("KO", 1);
			ft_putstr_fd(RESET, 1);
		}
		else
			ft_putendl_fd("KO", 1);
		exit(0);
	}
	*prev_help = cur;
	*help = cur->next;
}

void	check_sorting(t_list **head, t_list **head_b, t_bonus *bonus)
{
	t_list *cur;
	t_list *prev;

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
		greet_then_prev(&cur, &prev, bonus);
	if (bonus->c == 1)
	{
		ft_putstr_fd(GREEN, 1);
		ft_putendl_fd("OK", 1);
		ft_putstr_fd(RESET, 1);
	}
	else
		ft_putendl_fd("OK", 1);
}

void	sort_by_commands(t_list **head, t_list **head_b, t_bonus bonus)
{
	char	*line;
	int		size;

	line = NULL;
	if (!*head || *head_b)
		return ;
	while (get_next_line(0, &line) > 0)
	{
		size = ft_strlen(line);
		bonus.size = size;
		if (size == 3)
			exec_com_len_three(head, head_b, line, bonus);
		else if (size == 2)
		{
			exec_com_len_two(head, head_b, line, bonus);
			exec_com_len_two_two(head, head_b, line, bonus);
		}
		else if (size == -1)
			ft_putendl_fd("Error\n", 1);
		else if (size == 4)
			exec_com_len_four(head, head_b, line, bonus);
		free(line);
	}
	ft_putstr_fd("\b\b  \b\b", 1);
	check_sorting(head, head_b, &bonus);
}

int		main(int argc, char *argv[])
{
	t_list	*head;
	t_list	*tmp;
	t_list	*head_b;
	t_bonus	bonus;

	head = NULL;
	if (argc > 1 && (!ft_memcmp("-v", argv[1], 3) ||
	!ft_memcmp("-c", argv[1], 3)))
	{
		bonus.v = 1;
		argv++;
		argc--;
	}
	if (argc > 1 && (!ft_memcmp("-c", argv[1], 3) ||
	!ft_memcmp("-v", argv[1], 3)))
	{
		bonus.c = 1;
		argv++;
		argc--;
	}
	number_of_arguments(&argc, &argv);
	take_all_str(argc, argv, &tmp);
	create_array_value(argc, &head, &head_b, &tmp);
	sort_by_commands(&head, &head_b, bonus);
	return (0);
}
