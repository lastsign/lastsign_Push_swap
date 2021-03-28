/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:58:05 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 17:22:31 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;

	temp = begin_list;
	if (begin_list == NULL)
		return (NULL);
	while (temp != NULL)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
