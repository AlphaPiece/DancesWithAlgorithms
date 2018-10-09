/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:52:26 by zwang             #+#    #+#             */
/*   Updated: 2018/09/06 21:11:37 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	quick_sort(int *arr, int l, int r)
{
	int	i;
	int	last;

	if (l >= r)
		return ;
	ft_swap(&arr[l], &arr[(l + r) / 2]);
	last = l;
	i = l;
	while (++i <= r)
		if (arr[i] < arr[l])
			ft_swap(&arr[++last], &arr[i]);
	ft_swap(&arr[l], &arr[last]);
	quick_sort(arr, l, last - 1);
	quick_sort(arr, last + 1, r);
}

void		ft_quicksort(int *arr, size_t len)
{
	quick_sort(arr, 0, len - 1);
}
