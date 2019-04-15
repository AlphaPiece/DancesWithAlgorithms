/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:40:16 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 09:45:02 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int arr[], int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	shell_sort(int arr[], int len)
{
	int	gap, i, j;

	for (gap = len / 2; gap > 0; gap /= 2)
		for (i = gap; i < len; i++)
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
				swap(arr, j, j + gap);
}	
