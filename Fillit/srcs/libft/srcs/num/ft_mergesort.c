/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:04:01 by zwang             #+#    #+#             */
/*   Updated: 2018/09/06 13:26:30 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	merge(int *arr, int l, int m, int r)
{
	int		l_half[m - l + 1];
	int		r_half[r - m];	
	int		i;
	int		j;
	int		k;

	ft_numarrcpy(l_half, &arr[l], m - l + 1);
	ft_numarrcpy(r_half, &arr[m + 1], r - m);
	i = 0;
	j = 0;
	k = l;
	while (i < m - l + 1 && j < r - m)
	{
		if (l_half[i] < r_half[j])
			arr[k++] = l_half[i++];
		else
			arr[k++] = r_half[j++];
	}
	while (i < m - l + 1)
		arr[k++] = l_half[i++];
	while (j < r - m)
		arr[k++] = r_half[j++];
}

static void	merge_sort(int *arr, int l, int r)
{
	int		m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		printf("l: %2d r: %2d m: %2d\n", l, r, m);
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void		ft_mergesort(int *arr, size_t len)
{
	merge_sort(arr, 0, len - 1);
}
