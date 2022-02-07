/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srupert <srupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:32:53 by srupert           #+#    #+#             */
/*   Updated: 2022/02/07 23:20:31 by srupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define ULIMIT_N 10255

char	*get_next_line(int fd);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

#endif //GET_NEXT_LINE_BONUS_H
