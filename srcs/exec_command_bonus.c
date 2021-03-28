/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:56:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 16:56:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"

void	exec_debug_or_color(t_list **head, t_list **head_b, t_bonus *bonus)
{
	if (bonus->v == 1 && bonus->c == 1)
		debug_option_w_col(head, head_b);
	else if (bonus->v == 1)
		debug_option(head, head_b);
}

void	exec_com_len_two_two(t_list **head, t_list **head_b,
	char *line, t_bonus bonus)
{
	int	size;

	size = bonus.size;
	if (!ft_memcmp("rr\n", line, size))
	{
		ft_list_rotate(head);
		ft_list_rotate(head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("sa\n", line, size))
	{
		ft_list_swap(head);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("sb\n", line, size))
	{
		ft_list_swap(head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("ss\n", line, size))
	{
		ft_list_swap(head);
		ft_list_swap(head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
}

void	exec_com_len_two(t_list **head, t_list **head_b,
	char *line, t_bonus bonus)
{
	int	size;

	size = bonus.size;
	if (!ft_memcmp("pb\n", line, size))
	{
		ft_list_put(head, head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("pa\n", line, size))
	{
		ft_list_put(head_b, head);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("ra\n", line, size))
	{
		ft_list_rotate(head);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("rb\n", line, size))
	{
		ft_list_rotate(head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
}

void	exec_com_len_three(t_list **head, t_list **head_b,
	char *line, t_bonus bonus)
{
	int	size;

	size = bonus.size;
	if (!ft_memcmp("rra\n", line, size))
	{
		ft_list_rev_rotate(head);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("rrb\n", line, size))
	{
		ft_list_rev_rotate(head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
	else if (!ft_memcmp("rrr\n", line, size))
	{
		ft_list_rev_rotate(head);
		ft_list_rev_rotate(head_b);
		exec_debug_or_color(head, head_b, &bonus);
	}
}

void	exec_com_len_four(t_list **head, t_list **head_b,
	char *line, t_bonus bonus)
{
	int	size;

	size = bonus.size;
	if (!ft_memcmp("init\n", line, size))
		if (bonus.v == 1)
			debug_option(head, head_b);
}
