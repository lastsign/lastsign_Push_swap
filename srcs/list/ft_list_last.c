/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:36:43 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/04 20:54:41 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	t_list *tmp;

	tmp = begin_list;
	if (begin_list == NULL)
		return (begin_list);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
