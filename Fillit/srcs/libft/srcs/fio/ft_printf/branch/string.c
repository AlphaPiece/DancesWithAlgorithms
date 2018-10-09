/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:22:28 by zwang             #+#    #+#             */
/*   Updated: 2018/08/31 16:22:21 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	inner_process(t_package *package, t_strblock *block)
{
	if (package->collection['-'])
	{
		content_handler(package, block);
		width_handler(package, block);
	}
	else
	{
		width_handler(package, block);
		content_handler(package, block);
	}
}

void		string(t_package *package)
{
	t_strblock	*block;

	package->part = va_arg(*(package->args), char *);
	if (!package->part)
		package->part = "(null)";
	package->part_len = ft_strlen(package->part);
	block = find_last_block(package->strchain);
	package->collection['+'] = 0;
	if (package->collection['.'] && package->precision < (int)package->part_len)
	{
		package->part = ft_strsub(package->part, 0, package->precision);
		package->part_len = package->precision;
	}
	inner_process(package, block);
	if (package->collection['.'] && package->precision > 0 &&
		package->precision < (int)package->part_len)
		free(package->part);
}
