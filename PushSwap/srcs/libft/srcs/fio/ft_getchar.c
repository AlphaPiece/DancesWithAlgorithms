/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:34:06 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 10:50:41 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getchar(void)
{
	static char	buf[BUFSIZE] = {0};
	static int	i = 0;

	if (buf[i])
		return (buf[i++]);
	else if (buf[0] == -1)
		return (-1);
	else if (read(0, &buf, BUFSIZE) > 0)
	{
		i = 0;
		return (buf[i++]);
	}
	return (buf[0] = -1);
}
