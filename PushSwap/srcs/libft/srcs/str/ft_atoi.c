/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:52:55 by zwang             #+#    #+#             */
/*   Updated: 2018/08/12 20:44:35 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_result(long num)
{
	long	long_positive_limit;

	long_positive_limit = 9223372036854775807;
	if (num == long_positive_limit)
		return (-1);
	if (num == long_positive_limit * (-1) - 1)
		return (0);
	return ((int)num);
}

int			ft_atoi(const char *str)
{
	long	num;

	num = ft_atol(str);
	return (ft_atoi_result(num));
}
