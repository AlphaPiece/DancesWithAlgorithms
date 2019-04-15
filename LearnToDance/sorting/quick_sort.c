/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:52:26 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:12:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libal.h"

void	swap(int arr[], int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	quick_sort(int arr[], int l, int r)
{
	int	i;
	int	last;

	if (l >= r)
		return ;
	swap(arr, l, (l + r) / 2);
	last = l;
	i = l;
	while (++i <= r)
		if (arr[i] < arr[l])
			swap(arr, ++last, i);
	swap(arr, l, last);
	quick_sort(arr, l, last - 1);
	quick_sort(arr, last + 1, r);
}
