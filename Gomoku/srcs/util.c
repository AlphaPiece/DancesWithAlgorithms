/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:45:02 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/10 19:13:11 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

t_bool	is_over(char board[EDGE][EDGE])
{
	int		i, j;
	char	player;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
		{
			player = board[i][j];
			if (player == EMPTY)
				continue ;
			if (north_pieces(board, i, j, player) +
					south_pieces(board, i, j, player) >= PL - 1)
				return (true);
			if (east_pieces(board, i, j, player) +
					west_pieces(board, i, j, player) >= PL - 1)
				return (true);
			if (northwest_pieces(board, i, j, player) +
					southwest_pieces(board, i, j, player) >= PL - 1)
				return (true);
			if (northeast_pieces(board, i, j, player) +
					southwest_pieces(board, i, j, player) >= PL - 1)
				return (true);
		}
	return (false);
}

void	game_status(char board[EDGE][EDGE])
{
	int	i, j;

	ft_putchar('\n');
	ft_putnchar(' ', 6);
	for (i = 1; i < EDGE / 10 + 1; i++)
	{
		ft_putnchar(' ', 19);
		ft_putchar('0' + i % 10);
	}
	ft_printf("\n   0 |");
	for (i = 1; i <= EDGE; i++)
		ft_printf(" %d", i % 10);
	ft_putchar('\n');
	ft_putnchar(' ', 3);
	ft_putncharln('-', 3 + EDGE * 2);
	for (i = 1; i <= EDGE; i++)
	{
		if (i % 10 == 0)
			ft_printf("%2.d %d |", i / 10, i % 10);
		else
			ft_printf("   %d |", i % 10);
		for (j = 0; j < EDGE; j++)
			ft_printf(" %c", board[i - 1][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

t_bool	is_empty_place(char board[EDGE][EDGE], int r, int c)
{
	return (r >= 0 && r < EDGE && c >= 0 && c < EDGE && board[r][c] == EMPTY);
}

void	player_move(char board[EDGE][EDGE], char player)
{
	char	*buf, **coor;
	int		r, c;

	do
	{
		ft_printf("Place (row, column): ");
		ft_nextline(0, &buf);
		coor = ft_strsplit(buf, " \t\n,()");
		free(buf);
		if (ft_strarrlen((const char **)coor) < 2)
		{
			ft_strarrdel(coor);
			continue ;
		}
		r = ft_atoi(coor[0]) - 1;
		c = ft_atoi(coor[1]) - 1;
		ft_strarrdel(coor);
	} while (!is_empty_place(board, r, c));
	board[r][c] = player;
}
