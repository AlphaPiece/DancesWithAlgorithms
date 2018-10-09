/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:38:07 by zwang             #+#    #+#             */
/*   Updated: 2018/08/19 20:47:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_atol_result(int sign, unsigned long num)
{
	long	long_positive_limit;

	long_positive_limit = 9223372036854775807;
	if (sign > 0 && num >= (unsigned long)long_positive_limit)
		return (long_positive_limit);
	if (sign < 0 && num - 1 >= (unsigned long)long_positive_limit)
		return (long_positive_limit * (-1) - 1);
	return ((long)num * sign);
}

long		ft_atol(const char *str)
{
	unsigned long	num;
	int				sign;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (ft_atol_result(sign, num));
}
