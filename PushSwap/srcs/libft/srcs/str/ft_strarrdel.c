/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:51:17 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 20:20:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Assume arr is null-terminated and
** every element is allocated memory in heap.
*/

void	ft_strarrdel(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
