/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcs_td.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:28:45 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/16 15:12:31 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Longest Common Subsequence - Top Down
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	**tab;

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	lcs(char *p, char *q, int m, int n)
{
	if (tab[m][n] >= 0)
		return (tab[m][n]);
	else if (m == 0 || n == 0)
		return ((tab[m][n] = 0));
	else if (p[m - 1] == q[n - 1])
		return ((tab[m][n] = lcs(p, q, m - 1, n - 1) + 1));
	else
		return ((tab[m][n] = max(lcs(p, q, m - 1, n), lcs(p, q, m, n - 1))));
}

int	main(int argc, char **argv)
{
	int	len1;
	int	len2;

	if (argc == 3)
	{
		len1 = strlen(argv[1]);
		len2 = strlen(argv[2]);
		tab = (int **)malloc(sizeof(int *) * (len1 + 1));
		for (int i = 0; i < len1 + 1; i++)
			tab[i] = (int *)malloc(sizeof(int) * (len2 + 1));
		for (int i = 0; i < len1 + 1; i++)
			for (int j = 0; j < len2 + 1; j++)
					tab[i][j] = -1;
		printf("%d\n", lcs(argv[1], argv[2], len1, len2));
	}
	return (0);
}
