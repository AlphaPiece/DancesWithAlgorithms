/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:22:40 by zwang             #+#    #+#             */
/*   Updated: 2018/08/31 19:16:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character(t_package *package)
{
	t_strblock	*block;
	char		c;

	if (package->fmt_spfr == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(*(package->args), int);
	package->part_len = 1;
	package->precision = 0;
	block = find_last_block(package->strchain);
	package->collection['+'] = 0;
	package->collection['.'] = 0;
	if (package->collection['-'])
	{
		block->str[block->storage++] = c;
		width_handler(package, block);
	}
	else
	{
		width_handler(package, block);
		block->str[block->storage++] = c;
	}
}
