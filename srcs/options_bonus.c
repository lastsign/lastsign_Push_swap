/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:16:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 17:16:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"

void	print_table(t_list **info)
{
	int		i;
	t_list	*tmp;

	tmp = *info;
	i = ft_numlen(*(int *)tmp->data);
	while (13 - i > 0)
	{
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putnbr_fd(*(int *)tmp->data, 1);
	ft_putstr_fd("|", 1);
	(*info) = (*info)->next;
}

void	print_table_w_col(t_list **info)
{
	int		i;
	t_list	*tmp;

	tmp = *info;
	i = ft_numlen(*(int *)tmp->data);
	while (13 - i > 0)
	{
		ft_putstr_fd(" ", 1);
		i++;
	}
	if (tmp->col == 1)
	{
		tmp->col = 0;
		ft_putstr_fd(YELLOW, 1);
		ft_putnbr_fd(*(int *)tmp->data, 1);
		ft_putstr_fd(RESET, 1);
	}
	else
		ft_putnbr_fd(*(int *)tmp->data, 1);
	ft_putstr_fd("|", 1);
	(*info) = (*info)->next;
}

void	debug_option(t_list **head, t_list **head_b)
{
	t_list	*tmp;
	t_list	*tmp_b;

	tmp = *head;
	tmp_b = *head_b;
	ft_putstr_fd("+------A------+------B------+\n", 1);
	while (tmp || tmp_b)
	{
		ft_putstr_fd("|", 1);
		if (tmp)
			print_table(&tmp);
		else if (!tmp)
			ft_putstr_fd("             |", 1);
		if (tmp_b)
		{
			print_table(&tmp_b);
			ft_putstr_fd("\n", 1);
		}
		else
			ft_putstr_fd("             |\n", 1);
	}
	ft_putstr_fd("+-------------+-------------+\n", 1);
}

void	debug_option_w_col(t_list **head, t_list **head_b)
{
	t_list	*tmp;
	t_list	*tmp_b;

	tmp = *head;
	tmp_b = *head_b;
	ft_putstr_fd("+------A------+------B------+\n", 1);
	while (tmp || tmp_b)
	{
		ft_putstr_fd("|", 1);
		if (tmp)
			print_table_w_col(&tmp);
		else if (!tmp)
			ft_putstr_fd("             |", 1);
		if (tmp_b)
		{
			print_table_w_col(&tmp_b);
			ft_putstr_fd("\n", 1);
		}
		else
			ft_putstr_fd("             |\n", 1);
	}
	ft_putstr_fd("+-------------+-------------+\n", 1);
}
