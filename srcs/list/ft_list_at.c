/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:38:07 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/05 20:19:18 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	tmp = begin_list;
	if (begin_list == NULL)
		return (NULL);
	while (tmp && i < nbr)
	{
		i++;
		tmp = tmp->next;
	}
	if (i != nbr)
		return (NULL);
	return (tmp);
}
