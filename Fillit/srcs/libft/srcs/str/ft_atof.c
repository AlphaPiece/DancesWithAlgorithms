/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:16:00 by zwang             #+#    #+#             */
/*   Updated: 2018/08/25 12:38:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	integer_part;
	double	decimal_part;
	int		len;

	integer_part = (double)ft_atoi(str);
	while (*str && *(str - 1) != '.')
		str++;
	decimal_part = (double)ft_atoi(str);
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	while (len--)
		decimal_part /= 10;
	return (integer_part + ((integer_part > 0) ? decimal_part : -decimal_part));
}
