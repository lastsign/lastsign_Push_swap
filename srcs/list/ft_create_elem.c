/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 09:49:47 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/04 15:09:56 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_info	*info;
	t_list	*temp;
	t_bonus	*bonus;

	temp = malloc(sizeof(t_list));
	info = malloc(sizeof(t_info));
	bonus = malloc(sizeof(t_bonus));
	if (!temp || !info)
		return (NULL);
	temp->info = info;
	temp->bonus = bonus;
	temp->next = NULL;
	temp->data = data;
	temp->in = 0;
	temp->keep = 0;
	temp->c_com = 0;
	temp->col = 0;
	bonus->c = 0;
	bonus->v = 0;
	info->stack_a_rot = 0;
	info->stack_b_rot = 0;
	info->r_b = 0;
	info->r_a = 0;
	info->need_ra = 0;
	return (temp);
}
