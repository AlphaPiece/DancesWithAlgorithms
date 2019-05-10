/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_td.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:13:04 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/16 16:19:13 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cutting Rod - Top Down
*/

#include <stdio.h>
#include <stdlib.h>

int	*tab;

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	cr(int price[], int n)
{
	if (tab[n] >= 0)
		return (tab[n]);
	else if (n == 1)
		return ((tab[n] = price[n - 1]));
	else
	{
		tab[n] = price[n - 1];
		for (int i = 1; i <= (n >> 1); i++)
			tab[n] = max(tab[n], cr(price, n - i) + cr(price, i));
		return (tab[n]);
	}
}

int	main(int argc, char **argv)
{
	int	price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int	n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		tab = (int *)malloc(sizeof(int) * (n + 1));
		tab[0] = 0;
		for (int i = 1; i < n + 1; i++)
			tab[i] = -1;
		printf("%d\n", cr(price, n));
	}
	return (0);
}
