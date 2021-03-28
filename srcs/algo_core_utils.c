/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:49:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 15:49:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "push_swap.h"

void	cur_between_two_elem_in_a(t_list **help, t_help *h)
{
	t_list *cur;

	cur = *help;
	if (h->i_real_need <= h->push / 2)
	{
		cur->c_com += h->i_real_need;
		cur->info->r_a = h->i_real_need;
		cur->info->stack_a_rot = 1;
	}
	else
	{
		cur->c_com += h->push - h->i_real_need;
		cur->info->r_a = h->push - h->i_real_need;
		cur->info->stack_a_rot = 0;
	}
}

void	cur_less_then_a(t_list **help, t_help *h)
{
	t_list *cur;

	cur = *help;
	if (h->mi_in <= h->push / 2)
	{
		cur->c_com += h->mi_in;
		cur->info->r_a = h->mi_in;
		cur->info->stack_a_rot = 1;
	}
	else
	{
		cur->c_com += h->push - h->mi_in;
		cur->info->r_a = h->push - h->mi_in;
		cur->info->stack_a_rot = 0;
	}
}

void	cur_more_then_a(t_list **help, t_help *h)
{
	t_list *cur;

	cur = *help;
	if (h->ma_in <= h->push / 2)
	{
		cur->c_com += h->ma_in + 1;
		cur->info->r_a = h->ma_in + 1;
		cur->info->stack_a_rot = 1;
	}
	else
	{
		cur->c_com += h->push - h->ma_in - 1;
		cur->info->r_a = h->push - h->ma_in - 1;
		cur->info->stack_a_rot = 0;
	}
}

void	rebalance_a(t_list **head_a, t_help *h)
{
	t_list *tmp;

	while (h->i_real_need > 0)
	{
		ft_list_rev_rotate(head_a);
		h->i_real_need--;
	}
	h->i_real_need = 0;
	tmp = *head_a;
	while (tmp->in != h->real_need->in)
	{
		h->i_real_need++;
		tmp = tmp->next;
	}
}

void	find_pos_in_a(t_list **head_a, t_list **help, t_help *h)
{
	t_list *cur;

	cur = *help;
	while ((*head_a)->in != h->i_real_need_two)
	{
		ft_list_rotate(head_a);
		h->i_real_need++;
	}
	h->real_need = (*head_a)->next;
	h->real_need_p = *head_a;
	h->i_real_need_two = 0;
	while (h->real_need_p && h->real_need)
	{
		if (cur->in > h->real_need_p->in && cur->in < h->real_need->in)
			break ;
		h->i_real_need_two++;
		h->real_need_p = h->real_need;
		h->real_need = h->real_need->next;
	}
	if (!h->real_need)
		h->real_need = h->real_need_p;
}
