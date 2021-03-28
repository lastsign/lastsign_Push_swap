/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/13 21:17:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list **head)
{
	t_list *cur;
	t_list *tmp;

	if (!head || !*head)
		return ;
	cur = (*head)->next;
	tmp = *head;
	cur->col = 1;
	tmp->col = 1;
	(*head)->next = cur->next;
	cur->next = tmp;
	*head = cur;
}

void	ft_list_put(t_list **head_l, t_list **head_r)
{
	t_list *cur;

	if (!head_l || !*head_l || !head_r)
		return ;
	cur = (*head_l)->next;
	(*head_l)->next = *head_r;
	*head_r = *head_l;
	*head_l = cur;
	(*head_r)->col = 1;
}

void	ft_list_rotate(t_list **head)
{
	t_list *cur;
	t_list *p_cur;

	if (!head || !*head)
		return ;
	cur = *head;
	p_cur = cur;
	while (cur)
	{
		p_cur = cur;
		cur = cur->next;
	}
	cur = (*head)->next;
	p_cur->next = *head;
	(*head)->next = NULL;
	*head = cur;
	p_cur->next->col = 1;
}

void	ft_list_rev_rotate(t_list **head)
{
	t_list *cur;
	t_list *p_cur;

	if (!head || !*head)
		return ;
	cur = *head;
	p_cur = cur;
	while (cur->next)
	{
		p_cur = cur;
		cur = cur->next;
	}
	cur->next = *head;
	p_cur->next = NULL;
	*head = cur;
	(*head)->col = 1;
}
