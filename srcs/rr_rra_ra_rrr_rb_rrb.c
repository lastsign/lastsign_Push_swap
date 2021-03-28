/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rra_ra_rrr_rb_rrb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:58:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 15:58:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "push_swap.h"
#include <unistd.h>

void	rr_or_rrr(t_list **head_a, t_list **head_b, t_list **info)
{
	t_list	*cur;

	cur = *info;
	while (cur->info->r_b > 0 && cur->info->r_a > 0 &&
		((cur->info->stack_b_rot && cur->info->stack_a_rot) ||
		(!cur->info->stack_b_rot && !cur->info->stack_a_rot)))
	{
		if (cur->info->stack_b_rot && cur->info->stack_a_rot)
		{
			ft_list_rotate(head_a);
			ft_list_rotate(head_b);
			write(1, "rr\n", 3);
		}
		else if (!cur->info->stack_b_rot && !cur->info->stack_a_rot)
		{
			ft_list_rev_rotate(head_a);
			ft_list_rev_rotate(head_b);
			write(1, "rrr\n", 4);
		}
		cur->info->r_b--;
		cur->info->r_a--;
	}
}

void	rb_or_rrb(t_list **head_b, t_list **info)
{
	t_list	*cur;

	cur = *info;
	while (cur->info->r_b > 0)
	{
		if (cur->info->stack_b_rot)
		{
			ft_list_rotate(head_b);
			write(1, "rb\n", 3);
		}
		else
		{
			ft_list_rev_rotate(head_b);
			write(1, "rrb\n", 4);
		}
		cur->info->r_b--;
	}
}

void	ra_of_rra(t_list **head_a, t_list **info)
{
	t_list	*cur;

	cur = *info;
	while (cur->info->r_a > 0)
	{
		if (cur->info->stack_a_rot)
		{
			ft_list_rotate(head_a);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_list_rev_rotate(head_a);
			write(1, "rra\n", 4);
		}
		cur->info->r_a--;
	}
}
