/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:29:09 by zwang             #+#    #+#             */
/*   Updated: 2018/08/29 23:08:27 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pack_package(t_package **package, va_list *args,
									t_strblock *strchain)
{
	*package = (t_package *)malloc(sizeof(t_package));
	(*package)->args = args;
	(*package)->strchain = strchain;
}

static t_strblock	*black_box(const char *format, va_list *args)
{
	char		*percent;
	t_strblock	*strchain;
	t_package	*package;

	strchain = create_strblock();
	pack_package(&package, args, strchain);
	while ((percent = ft_strchr(format, '%')))
	{
		if (*format != '%')
			str_handler(strchain, format, percent);
		format = fmt_handler(package, percent + 1);
	}
	if (*format)
		str_handler(strchain, format, NULL);
	free(package);
	return (strchain);
}

int					ft_printf(const char *format, ...)
{
	va_list		args;
	t_strblock	*strchain;
	int			total_char;
	t_strblock	*tmp;

	va_start(args, format);
	strchain = black_box(format, &args);
	va_end(args);
	total_char = 0;
	while (strchain)
	{
		write(1, strchain->str, strchain->storage);
		total_char += strchain->storage;
		tmp = strchain;
		strchain = strchain->next;
		free(tmp);
	}
	return (total_char);
}
