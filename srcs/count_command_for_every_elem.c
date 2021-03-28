/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_command_for_every_elem.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:01:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 16:01:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "push_swap.h"
#include <unistd.h>

int		sa_is_needed(t_list **head, t_list *cur, int max_m)
{
	int	m;

	ft_list_swap(head);
	m = number_of_remaining(cur);
	if (m <= max_m)
		ft_list_swap(head);
	else
	{
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

void	to_top_in_b(t_list **head_b)
{
	int		push;
	int		keep;
	t_list	*cur;

	push = ft_list_size(*head_b);
	keep = 0;
	cur = *head_b;
	while (cur)
	{
		if (keep <= push / 2)
		{
			cur->c_com = keep;
			cur->info->r_b = keep;
			cur->info->stack_b_rot = 1;
		}
		else
		{
			cur->c_com = push - keep;
			cur->info->r_b = push - keep;
			cur->info->stack_b_rot = 0;
		}
		cur = cur->next;
		keep++;
	}
}

void	push_to_b(t_list **head_a, t_list **head_b, int push, int keep)
{
	t_list *cur;

	cur = make_markup_by_in(*head_a);
	keep = number_of_remaining(cur);
	push = ft_list_size(*head_a) - keep;
	while (push > 0)
	{
		if (sa_is_needed(head_a, cur, keep))
		{
			keep++;
			push--;
		}
		else if ((*head_a)->keep == 0)
		{
			ft_list_put(head_a, head_b);
			write(1, "pb\n", 3);
			push--;
		}
		else
		{
			ft_list_rotate(head_a);
			write(1, "ra\n", 3);
		}
	}
}

void	align_stack_a(t_list **head_a, int keep, int push)
{
	t_list	*cur;

	keep = 0;
	push = ft_list_size(*head_a);
	cur = *head_a;
	while (cur)
	{
		if (cur->in == 0)
			break ;
		cur = cur->next;
		keep++;
	}
	while ((*head_a)->in != 0)
	{
		if (keep <= push / 2)
		{
			ft_list_rotate(head_a);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_list_rev_rotate(head_a);
			write(1, "rra\n", 4);
		}
	}
}
