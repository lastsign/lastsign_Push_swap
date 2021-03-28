/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:03:35 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 20:22:59 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *temp;

	if (begin_list == NULL)
		return ;
	temp = begin_list;
	while (temp != NULL)
	{
		(*f)(temp->data);
		temp = temp->next;
	}
}
