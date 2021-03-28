/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:48:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/03/26 17:48:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "push_swap.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	t_win	*data;
	char	*dst;

	data = win;
	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_background(t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->h)
	{
		x = 0;
		while (x < win->w / 2)
			my_mlx_pixel_put(win, x++, y, 0x424242);
		while (x < win->w)
			my_mlx_pixel_put(win, x++, y, 0x2e2e2e);
		y++;
	}
}

void	draw_stack_a(t_list **head, t_win *win)
{
	int		x;
	int		y;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		y = i * win->c;
		while (y < (i + 1) * win->c)
		{
			x = 0;
			while (x < (tmp->in + 1) * win->c)
			{
				my_mlx_pixel_put(win, x, y, 0xd6cb2b);
				x++;
			}
			y++;
		}
		tmp = tmp->next;
		i++;
	}
}

void	draw_stack_b(t_list **head_b, t_win *win)
{
	int		x;
	int		y;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head_b;
	while (tmp)
	{
		y = i * win->c;
		while (y < (i + 1) * win->c)
		{
			x = win->w / 2;
			while (x < (tmp->in + 1) * win->c + win->h)
			{
				my_mlx_pixel_put(win, x, y, 0xd6cb2b);
				x++;
			}
			y++;
		}
		tmp = tmp->next;
		i++;
	}
}

void	draw(t_list **head, t_list **head_b, t_win *win)
{
	draw_background(win);
	draw_stack_a(head, win);
	draw_stack_b(head_b, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_do_sync(win->mlx);
}
