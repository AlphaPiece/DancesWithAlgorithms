/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcs_bu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:00:20 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/16 15:11:55 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Longest Common Subsequence - Bottom Up
*/

#include <stdio.h>
#include <string.h>	

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	lcs(char *p, char *q, int m, int n)
{
	int	tab[m + 1][n + 1];
	int	i, j;

	for (i = 0; i <= m; i++)
		for (j = 0; j <= n; j++)
			if (i == 0 || j == 0)
				tab[i][j] = 0;
			else if (p[i - 1] == q[j - 1])
				tab[i][j] = tab[i - 1][j - 1] + 1;
			else
				tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
	return (tab[m][n]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", lcs(argv[1], argv[2],
							strlen(argv[1]), strlen(argv[2])));
	return (0);
}
