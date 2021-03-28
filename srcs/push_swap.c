/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:11:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/12 20:11:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_list	*head;
	t_list	*head_b;
	t_list	*tmp;

	tmp = NULL;
	number_of_arguments(&argc, &argv);
	if (argc != 4)
	{
		take_all_str(argc, argv, &tmp);
		create_array_value(argc, &head, &head_b, &tmp);
		from_a_to_b_by_mark(&head, &head_b);
	}
	else
	{
		take_all_str(argc, argv, &tmp);
		create_array_value(argc, &head, &head_b, &tmp);
		if (!check_three_cases(head))
			check_two_last_cases(head);
	}
	return (0);
}
