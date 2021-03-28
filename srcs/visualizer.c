/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:15:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/23 14:15:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_list.h"
#include "libft.h"
#include "push_swap.h"
#include "mlx.h"

int		my_close(t_win *win)
{
	if (win)
		exit(0);
	return (0);
}

void	check_sorting(t_list **head, t_list **head_b)
{
	t_list	*cur;
	t_list	*prev;

	if (!*head)
		return ;
	if (ft_list_size(*head_b) != 0)
	{
		ft_putendl_fd("KO", 1);
		exit(0);
	}
	cur = (*head)->next;
	prev = *head;
	while (cur)
	{
		if (*(int*)cur->data < *(int*)prev->data)
		{
			ft_putendl_fd("KO", 1);
			exit(0);
		}
		prev = cur;
		cur = cur->next;
	}
	ft_putendl_fd("OK", 1);
}

void	exec_command(t_list **head, t_list **head_b, char *line)
{
	int	size;

	size = ft_strlen(line);
	if (size == 3)
		exec_command_size_three(head, head_b, line, size);
	else if (size == 2)
		exec_command_size_two(head, head_b, line, size);
}

void	sort_by_commands(t_list **head, t_list **head_b, t_win *win)
{
	char	*line;

	line = NULL;
	mlx_hook(win->win, 17, (1L << 17), &my_close, &win);
	draw(head, head_b, win);
	while (get_next_line(0, &line) > 0)
	{
		exec_command(head, head_b, line);
		free(line);
		draw(head, head_b, win);
	}
	mlx_loop(win->mlx);
}

int		main(int argc, char *argv[])
{
	t_win	win;
	t_list	*tmp;
	t_list	*head;
	t_list	*head_b;

	tmp = NULL;
	head_b = NULL;
	number_of_arguments(&argc, &argv);
	take_all_str(argc, argv, &tmp);
	create_array_value(argc, &head, &head_b, &tmp);
	win.w = 1800;
	win.h = 900;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.w, win.h, "Push swap");
	win.img = mlx_new_image(win.mlx, win.w, win.h);
	win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_l, &win.en);
	win.c = win.h / ft_list_size(head);
	sort_by_commands(&head, &head_b, &win);
	return (0);
}
