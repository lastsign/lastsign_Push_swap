/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:39:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 17:39:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"

void	exec_command_size_three(t_list **head, t_list **head_b,
	char *line, int size)
{
	if (!ft_memcmp("rra\n", line, size))
		ft_list_rev_rotate(head);
	else if (!ft_memcmp("rrb\n", line, size))
		ft_list_rev_rotate(head_b);
	else if (!ft_memcmp("rrr\n", line, size))
	{
		ft_list_rev_rotate(head);
		ft_list_rev_rotate(head_b);
	}
}

void	exec_command_size_two(t_list **head, t_list **head_b,
	char *line, int size)
{
	if (!ft_memcmp("pb\n", line, size))
		ft_list_put(head, head_b);
	else if (!ft_memcmp("pa\n", line, size))
		ft_list_put(head_b, head);
	else if (!ft_memcmp("ra\n", line, size))
		ft_list_rotate(head);
	else if (!ft_memcmp("rb\n", line, size))
		ft_list_rotate(head_b);
	else if (!ft_memcmp("rr\n", line, size))
	{
		ft_list_rotate(head);
		ft_list_rotate(head_b);
	}
	else if (!ft_memcmp("sa\n", line, size))
		ft_list_swap(head);
	else if (!ft_memcmp("sb\n", line, size))
		ft_list_swap(head_b);
	else if (!ft_memcmp("ss\n", line, size))
	{
		ft_list_swap(head);
		ft_list_swap(head_b);
	}
}
