/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:26:10 by zwang             #+#    #+#             */
/*   Updated: 2018/08/31 10:17:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbits_i(unsigned long n)
{
	unsigned long	i;
	unsigned long	one;

	one = 1;
	i = one << 63;
	while (i > 0)
	{
		(n & i) ? ft_putchar('1') : ft_putchar('0');
		i /= 2;
	}
	ft_putchar('\n');
}
