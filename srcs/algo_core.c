/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:46:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 15:46:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void	find_min_a(t_list **head_a, t_help *h)
{
	t_list *tmp;

	h->i_real_need = 0;
	h->i_real_need_two = INT32_MAX;
	tmp = *head_a;
	while (tmp)
	{
		if (h->i_real_need_two > tmp->in)
			h->i_real_need_two = tmp->in;
		tmp = tmp->next;
	}
}

void	find_max_n_min_in_a(t_list **head_a, t_help *h)
{
	t_list	*tmp;
	int		i;

	h->push = ft_list_size(*head_a);
	h->max = *head_a;
	h->min = *head_a;
	h->ma_in = 0;
	h->mi_in = 0;
	i = 0;
	tmp = *head_a;
	while (tmp)
	{
		if (tmp->in > h->max->in)
		{
			h->max = tmp;
			h->ma_in = i;
		}
		if (tmp->in < h->min->in)
		{
			h->min = tmp;
			h->mi_in = i;
		}
		i++;
		tmp = tmp->next;
	}
}

void	way_to_top_of_b(t_list *cur, t_help *h)
{
	while (cur)
	{
		if (h->keep <= h->push / 2)
		{
			cur->c_com = h->keep;
			cur->info->r_b = h->keep;
			cur->info->stack_b_rot = 1;
		}
		else
		{
			cur->c_com = h->push - h->keep;
			cur->info->r_b = h->push - h->keep;
			cur->info->stack_b_rot = 0;
		}
		cur = cur->next;
		h->keep++;
	}
}

void	calculate_num_of_comm(t_list **head_a, t_list **head_b)
{
	t_help h;
	t_list *cur;

	h.push = ft_list_size(*head_b);
	h.keep = 0;
	cur = *head_b;
	way_to_top_of_b(cur, &h);
	find_max_n_min_in_a(head_a, &h);
	cur = *head_b;
	while (cur)
	{
		find_min_a(head_a, &h);
		find_pos_in_a(head_a, &cur, &h);
		rebalance_a(head_a, &h);
		if (cur->in > h.max->in)
			cur_more_then_a(&cur, &h);
		else if (cur->in < h.min->in)
			cur_less_then_a(&cur, &h);
		else
			cur_between_two_elem_in_a(&cur, &h);
		cur = cur->next;
	}
}

void	from_a_to_b_by_mark(t_list **head_a, t_list **head_b)
{
	int		push;
	t_list	*cur;
	t_list	*min_c;

	push_to_b(head_a, head_b, 0, 0);
	push = ft_list_size(*head_b);
	while (push-- > 0)
	{
		calculate_num_of_comm(head_a, head_b);
		min_c = *head_b;
		cur = *head_b;
		while (cur)
		{
			if (cur->c_com < min_c->c_com)
				min_c = cur;
			cur = cur->next;
		}
		cur = min_c;
		rr_or_rrr(head_a, head_b, &cur);
		rb_or_rrb(head_b, &cur);
		ra_of_rra(head_a, &cur);
		ft_list_put(head_b, head_a);
		write(1, "pa\n", 3);
	}
	align_stack_a(head_a, 0, 0);
}
