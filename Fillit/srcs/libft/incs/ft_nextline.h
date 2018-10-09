/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:44:39 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 09:48:09 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 42
# define NL_INDEX (nlc - buffer)
# define MALLOC_FREE(x, y, z) x = y; y = z; free(x);

typedef	struct		s_file
{
	int				fd;
	char			*save;
	struct s_file	*next;
}					t_file;

int					ft_nextline(const int fd, char **line);

#endif
