/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:33:26 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/10 19:04:44 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_H
# define GOMOKU_H

# include "libft.h"

# define PL		5
# define EDGE	15
# define EMPTY	'.'

int		north_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		south_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		west_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		east_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		northwest_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		northeast_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		southwest_pieces(char board[EDGE][EDGE], int r, int c, char player);
int		southeast_pieces(char board[EDGE][EDGE], int r, int c, char player);

t_bool	is_over(char board[EDGE][EDGE]);
void	game_status(char board[EDGE][EDGE]);
t_bool	is_empty_place(char board[EDGE][EDGE], int r, int c);
void	player_move(char board[EDGE][EDGE], char player);

#endif
