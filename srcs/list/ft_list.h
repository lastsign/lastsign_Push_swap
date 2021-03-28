/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:22:26 by ptycho            #+#    #+#             */
/*   Updated: 2020/08/04 20:47:24 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stddef.h>

typedef struct		s_bonus
{
	int				v;
	int				c;
	int				size;
}					t_bonus;

typedef struct		s_info
{
	int				stack_b_rot;
	int				r_b;
	int				stack_a_rot;
	int				r_a;
	int				need_ra;

}					t_info;

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
	int				in;
	int				keep;
	int				c_com;
	int				col;
	t_info			*info;
	t_bonus			*bonus;
}					t_list;

typedef struct		s_help
{
	int				push;
	int				keep;
	t_list			*max;
	t_list			*min;
	t_list			*real_need;
	t_list			*real_need_p;
	int				ma_in;
	int				mi_in;
	int				i_real_need;
	int				i_real_need_two;
	int				i;
}					t_help;

t_list				*ft_create_elem(void *data);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_clear(t_list **begin_list);
t_list				*ft_list_find(t_list *begin_list,
	void *data_ref, int (*cmp)());
void				ft_list_foreach(t_list *begin_list,
	void (*f)(void *));
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
					void *data_ref, int (*cmp)(void *, void *));
t_list				*ft_list_last(t_list *begin_list);
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_remove_if(t_list **begin_list,
	void *data_ref, int (*cmp)());
void				ft_list_reverse(t_list **begin_list);
int					ft_list_size(t_list *begin_list);
void				ft_list_swap(t_list **head);
void				ft_list_put(t_list **head_l, t_list **head_r);
void				ft_list_rotate(t_list **head);
void				ft_list_rev_rotate(t_list **head);

#endif
