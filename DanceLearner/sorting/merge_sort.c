/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:04:01 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 14:58:38 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libal.h"

static void	merge(int *arr, int l, int m, int r)
{
	int		len_1 = m - l + 1;
	int		len_2 = r - m;
	int		l_half[len_1], r_half[len_2];
	int		i = 0, j = 0, k = l;
	
	for (i = 0; i < len_1; i++)
		l_half = arr[l + i];
	for (j = 0; i < len_2; j++)
		r_half = arr[m + 1 + j];
	while (i < len_1 && j < len_2)
	{
		if (l_half[i] < r_half[j])
			arr[k++] = l_half[i++];
		else
			arr[k++] = r_half[j++];
	}
	while (i < len_1)
		arr[k++] = l_half[i++];
	while (j < len_2)
		arr[k++] = r_half[j++];
}

void		merge_sort(int *arr, int l, int r)
{
	int		m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
