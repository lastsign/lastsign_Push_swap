/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:28:16 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 20:23:54 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),\
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list *temp;

	if (begin_list == NULL)
		return ;
	temp = begin_list;
	while (temp != NULL)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
		{
			(*f)(temp->data);
		}
		temp = temp->next;
	}
}
