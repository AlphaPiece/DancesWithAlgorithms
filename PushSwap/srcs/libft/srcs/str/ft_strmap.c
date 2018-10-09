/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:03:27 by zwang             #+#    #+#             */
/*   Updated: 2018/08/31 22:09:07 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ns;
	size_t	i;

	if (!s || !(*s) || !(f) ||
			!(ns = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ns[i] = f(s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
