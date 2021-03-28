/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:03:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/14 21:03:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# include "ft_list.h"

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				line_l;
	int				bpp;
	int				en;
	int				c;
	int				w;
	int				h;
}					t_win;

t_list				*make_markup_by_in(t_list *head);
int					number_of_remaining(t_list *head);
char				**check_argum(int *argc, char **argv);
void				check_argums(int argc, char **argv);
void				an_exception(void);
int					sa_is_needed(t_list **head, t_list *cur, int max_m);
int					check_three_cases(t_list *head);
void				check_two_last_cases(t_list *head);
void				free_old_list(t_list **head, t_list **tmp);
void				calculate_num_of_comm(t_list **head_a, t_list **head_b);
void				rr_or_rrr(t_list **head_a, t_list **head_b, t_list **info);
void				rb_or_rrb(t_list **head_b, t_list **info);
void				ra_of_rra(t_list **head_a, t_list **info);
void				push_to_b(t_list **head_a, t_list **head_b,
	int push, int keep);
void				align_stack_a(t_list **head_a, int keep, int push);
void				from_a_to_b_by_mark(t_list **head_a, t_list **head_b);
void				number_of_arguments(int *argc, char ***argv);
void				take_all_str(int argc, char **argv, t_list **tmp);
void				create_array_value(int argc, t_list **head,
	t_list **head_b, t_list **tmp);
void				exec_com_len_two(t_list **head, t_list **head_b,
	char *line, t_bonus bonus);
void				exec_com_len_two_two(t_list **head, t_list **head_b,
	char *line, t_bonus bonus);
void				exec_com_len_three(t_list **head, t_list **head_b,
	char *line, t_bonus bonus);
void				exec_com_len_four(t_list **head, t_list **head_b,
	char *line, t_bonus bonus);
void				debug_option_w_col(t_list **head, t_list **head_b);
void				debug_option(t_list **head, t_list **head_b);
int					ft_numlen(int a);
void				exec_command_size_three(t_list **head, t_list **head_b,
	char *line, int size);
void				exec_command_size_two(t_list **head, t_list **head_b,
	char *line, int size);
void				draw(t_list **head, t_list **head_b, t_win *win);
void				find_pos_in_a(t_list **head_a, t_list **help, t_help *h);
void				rebalance_a(t_list **head_a, t_help *h);
void				cur_more_then_a(t_list **help, t_help *h);
void				cur_less_then_a(t_list **help, t_help *h);
void				cur_between_two_elem_in_a(t_list **help, t_help *h);

#endif
