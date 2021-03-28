/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:27:42 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 20:48:39 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *first;
	t_list *second;

	if (begin_list1 == NULL || begin_list2 == NULL)
		return ;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
	}
	first = *begin_list1;
	while (first->next != NULL)
		first = first->next;
	second = begin_list2;
	while (second != NULL)
	{
		first->next = second;
		first = second;
		second = second->next;
	}
}
