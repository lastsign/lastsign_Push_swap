/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:21:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 21:21:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	recovery(long *a, int i, int n)
{
	long	temp;
	int		k;
	int		l;
	int		r;

	k = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && a[l] > a[k])
		k = l;
	if (r < n && a[r] > a[k])
		k = r;
	if (k != i)
	{
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
		recovery(a, k, n);
	}
}

void	heap_sort(long *a, int n)
{
	long	temp;
	int		i;
	int		d;

	i = n / 2 - 1;
	while (i >= 0)
	{
		recovery(a, i, n);
		i--;
	}
	d = n - 1;
	while (d > 0)
	{
		temp = a[0];
		a[0] = a[d];
		a[d] = temp;
		recovery(a, 0, d);
		d--;
	}
}
