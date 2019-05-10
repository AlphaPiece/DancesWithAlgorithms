/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_bu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:52:08 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/16 16:19:10 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cutting Rod - Bottom Up
*/

#include <stdio.h>
#include <stdlib.h>

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	cr(int price[], int n)
{
	int	val[n + 1];
	int	i, j;

	val[0] = 0;
	for (i = 1; i <= n; i++)
	{
		val[i] = price[i - 1];
		for (j = 1; j < (i >> 1) + 1; j++)
			val[i] = max(val[i], val[j] + val[i - j]);
	}
	return (val[n]);
}

int	main(int argc, char **argv)
{
	int	price[] = {1, 5, 8, 9, 10, 17, 17, 20};

	if (argc == 2)
		printf("%d\n", cr(price, atoi(argv[1])));
	return (0);
}
