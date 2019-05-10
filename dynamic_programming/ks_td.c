/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_td.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:08:49 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/22 16:29:01 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Knapsack - Top Down
*/

#include <stdio.h>
#include <stdlib.h>

int	**dp;

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	ks(int val[], int wt[], int n, int w)
{
	if (dp[n][w] >= 0)
		return (dp[n][w]);
	else if (n == 0 || w == 0)
		return ((dp[n][w] = 0));
	else if (wt[n - 1] > w)
		return ((dp[n][w] = ks(val, wt, n - 1, w)));
	else
		return ((dp[n][w] = max(val[n - 1] + ks(val, wt, n - 1, w - wt[n - 1]),
								ks(val, wt, n - 1, w))));
}

int	main(void)
{	
	int	val[] = {60, 100, 120};
	int	wt[] = {10, 20, 30};
	int	w = 50;
	int	n = 3;

	dp = (int **)malloc(sizeof(int *) * (n + 1));
	for (int i = 0; i <= n; i++)
		dp[i] = (int *)malloc(sizeof(int) * (w + 1));
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= w; j++)
			dp[i][j] = -1;
	printf("%d\n", ks(val, wt, n, w));
	return (0);
}
