/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iselem_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:04:30 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 10:38:21 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_iselem_long(long *arr, size_t len, long num)
{
	size_t	i;

	i = 0;
	while (i < len)
		if (arr[i++] == num)
			return (true);
	return (false);
}
