/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_afree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:29:35 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 11:18:37 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ALLOCSIZE:	size of available space
*/

#define ALLOCSIZE	10000

/*
** allocbuf:	storage for alloc
** allocptr:	pointer to next free position
*/

static char	allocbuf[ALLOCSIZE];
static char	*allocptr = allocbuf;

char	*alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocptr >= n)
	{
		allocptr += n;
		return (allocptr - n);
	}
	else
		return (NULL);
}

void	afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocptr = p;
}
