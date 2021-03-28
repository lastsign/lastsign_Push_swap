/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:43:16 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 17:26:06 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *prev_tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	prev_tmp = *begin_list;
	tmp = prev_tmp->next;
	while (tmp != NULL)
	{
		free(prev_tmp);
		prev_tmp = tmp;
		tmp = tmp->next;
	}
	*begin_list = NULL;
}
