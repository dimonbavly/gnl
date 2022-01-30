/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srupert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 09:50:59 by srupert           #+#    #+#             */
/*   Updated: 2022/01/30 09:51:03 by srupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <malloc.h>
# include <unistd.h>
# define ULIMIT_N 4096

char	*get_next_line_bonus(int fd);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

#endif //GET_NEXT_LINE_BONUS_H
