/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:30:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/10 19:16:24 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

void	game_loop(char board[EDGE][EDGE])
{
	char	player;

	ft_printf("\nGame starts!\n");
	player = 'X';
	while (true)
	{
		game_status(board);
		player_move(board, player);
		if (is_over(board))
			break ;
		player = (player == 'X') ? 'O' : 'X';
	}
	game_status(board);
	ft_printf("\nGame over.\n");
	ft_printf("Player %c won!\n", player);
}

int		main(void)
{
	char	board[EDGE][EDGE];
	int		i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			board[i][j] = '.';
	game_loop(board);
	return (0);
}
