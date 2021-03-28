/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:56:30 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 20:21:13 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list *temp;
	t_list *cur;
	t_list *prev;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	prev = *begin_list;
	cur = prev->next;
	prev->next = NULL;
	while (cur != NULL)
	{
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	*begin_list = prev;
}
