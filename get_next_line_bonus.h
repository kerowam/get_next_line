/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:16:52 by gfredes-          #+#    #+#             */
/*   Updated: 2023/04/01 23:36:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char		*get_next_line(int fd);
char		*make_line(char *stack);
char		*update_stack(char *stack);
char		*ft_reader(int fd, char *stack);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char		*ft_strdup(char *s1);

#endif
