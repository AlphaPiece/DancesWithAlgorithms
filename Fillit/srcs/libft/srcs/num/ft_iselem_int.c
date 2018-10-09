/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iselem_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:06:48 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 10:37:54 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_iselem_int(int *arr, size_t len, int num)
{
	size_t	i;

	i = 0;
	while (i < len)
		if (arr[i++] == num)
			return (true);
	return (false);
}
