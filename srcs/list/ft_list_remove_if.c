/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:25:08 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 20:04:32 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove(t_list **begin_list, t_list *temp, t_list *temp_prev)
{
	if (*begin_list == temp)
	{
		*begin_list = temp->next;
		free(temp);
	}
	else if (temp->next == NULL)
	{
		if (temp_prev == NULL)
			*begin_list = NULL;
		else
			temp_prev->next = NULL;
		free(temp);
	}
	else
	{
		temp_prev->next = temp->next;
		free(temp);
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;
	t_list *temp_prev;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	temp = *begin_list;
	while (temp != NULL)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
		{
			ft_list_remove(begin_list, temp, temp_prev);
		}
		temp_prev = temp;
		temp = temp->next;
	}
}
