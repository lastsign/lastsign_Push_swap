/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:43:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 15:43:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"

int		check_three_cases(t_list *head)
{
	if (*(int *)head->data > *(int *)head->next->data &&
		*(int *)head->data < *(int *)head->next->next->data &&
		*(int *)head->next->data < *(int *)head->next->next->data)
	{
		ft_list_swap(&head);
		ft_putstr_fd("sa\n", 1);
	}
	else if (*(int *)head->data > *(int *)head->next->data &&
		*(int *)head->data > *(int *)head->next->next->data &&
		*(int *)head->next->data > *(int *)head->next->next->data)
	{
		ft_list_swap(&head);
		ft_list_rev_rotate(&head);
		ft_putstr_fd("sa\nrra\n", 1);
	}
	else if (*(int *)head->data > *(int *)head->next->data &&
		*(int *)head->data > *(int *)head->next->next->data &&
		*(int *)head->next->data < *(int *)head->next->next->data)
	{
		ft_list_rotate(&head);
		ft_putstr_fd("ra\n", 1);
	}
	else
		return (0);
	return (1);
}

void	check_two_last_cases(t_list *head)
{
	if (*(int*)head->data < *(int *)head->next->data &&
		*(int*)head->data < *(int *)head->next->next->data &&
		*(int*)head->next->data > *(int *)head->next->next->data)
	{
		ft_list_swap(&head);
		ft_putstr_fd("sa\n", 1);
		ft_list_rotate(&head);
		ft_putstr_fd("ra\n", 1);
	}
	else if (*(int *)head->data < *(int *)head->next->data &&
		*(int *)head->data > *(int *)head->next->next->data &&
		*(int *)head->next->data > *(int *)head->next->next->data)
	{
		ft_list_rev_rotate(&head);
		ft_putstr_fd("rra\n", 1);
	}
}

void	set_markup_res(t_list *head)
{
	t_list	*cur;

	cur = head;
	while (cur)
	{
		cur->keep = 0;
		cur = cur->next;
	}
}

int		number_of_remaining(t_list *head)
{
	int		i;
	t_list	*cur;
	t_list	*p_cur;

	i = 1;
	cur = head;
	p_cur = head;
	while (cur)
	{
		if (cur->in == p_cur->in + 1)
		{
			i++;
			cur->keep = 1;
			p_cur->keep = 1;
			p_cur = cur;
		}
		cur = cur->next;
	}
	return (i);
}

t_list	*make_markup_by_in(t_list *head)
{
	t_list	*cur;
	t_list	*p_cur;
	int		max_mark;
	int		n;

	max_mark = 0;
	cur = head;
	p_cur = head;
	while (cur)
	{
		set_markup_res(head);
		n = number_of_remaining(cur);
		if (n > max_mark)
		{
			p_cur = cur;
			max_mark = n;
		}
		else if (n == max_mark)
			if (cur->in < p_cur->in)
				p_cur = cur;
		cur = cur->next;
	}
	number_of_remaining(p_cur);
	return (p_cur);
}
