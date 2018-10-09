/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:07:12 by zwang             #+#    #+#             */
/*   Updated: 2018/08/29 14:38:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	modify_signed_integer(t_package *package)
{
	intmax_t	num;

	if (package->collection['j'] >= 1)
		num = va_arg(*(package->args), intmax_t);
	else if (package->collection['l'] >= 2)
		num = va_arg(*(package->args), long long);
	else if (package->collection['l'] == 1)
		num = va_arg(*(package->args), long);
	else if (package->collection['z'] >= 1)
		num = va_arg(*(package->args), ssize_t);
	else if (package->collection['h'] == 1)
		num = (signed short)va_arg(*(package->args), int);
	else if (package->collection['h'] >= 2)
		num = (signed char)va_arg(*(package->args), int);
	else
		num = va_arg(*(package->args), int);
	return (num);
}

uintmax_t	modify_unsigned_integer(t_package *package)
{
	uintmax_t	num;

	if (package->collection['j'] >= 1)
		num = va_arg(*(package->args), uintmax_t);
	else if (package->collection['l'] >= 2)
		num = va_arg(*(package->args), unsigned long long);
	else if (package->collection['l'] == 1)
		num = va_arg(*(package->args), unsigned long);
	else if (package->collection['z'] >= 1)
		num = va_arg(*(package->args), size_t);
	else if (package->collection['h'] == 1)
		num = (unsigned short)va_arg(*(package->args), int);
	else if (package->collection['h'] >= 2)
		num = (unsigned char)va_arg(*(package->args), int);
	else
		num = va_arg(*(package->args), unsigned int);
	return (num);
}
