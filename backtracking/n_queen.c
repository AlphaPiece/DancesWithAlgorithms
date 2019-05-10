/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:03:42 by zwang             #+#    #+#             */
/*   Updated: 2019/03/09 17:25:18 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define N	10

int		is_safe(int board[N][N], int row, int col)
{
	int	i, j;

	for (j = 0; j <= col; j++)
		if (board[row][j])
			return (0);
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return (0);
	for (i = row, j = col; i < N && j >= 0; i++, j--)
		if (board[i][j])
			return (0);
	return (1);
}

int		check_pattern(int board[N][N], int col)
{
	if (col == N)
		return (1);
	for (int i = 0; i < N; i++)
		if (is_safe(board, i, col))
		{
			board[i][col] = 1;
			if (check_pattern(board, col + 1))
				return (1);
			board[i][col] = 0;
		}
	return (0);
}

void	print_board(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%2d", board[i][j]);
		printf("\n");
	}
}

int		solve_board(void)
{
	int	board[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = 0;
	if (check_pattern(board, 0))
	{
		print_board(board);
		return (1);
	}
	printf("Fail to find a solution.\n");
	return (0);
}

int		main(void)
{
	solve_board();
	return (0);
}
