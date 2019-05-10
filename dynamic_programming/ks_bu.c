/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_bu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:11:47 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/22 16:27:53 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Knapsack - Bottom Up
*/

#include <stdio.h>

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	ks(int val[], int wt[], int n, int w)
{
	int	dp[n + 1][w + 1];
	int	i;
	int	j;

	for (i = 0; i <= n; i++)
		for (j = 0; j <= w; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (wt[i - 1] <= j)
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]],
								dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
	return (dp[n][w]);
}

int	main(void)
{
	int	val[] = {60, 100, 120};
	int	wt[] = {10, 20, 30};
	int	w = 50;
	int	n = 3;

	printf("%d\n", ks(val, wt, n, w));
	return (0);
}
