/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:14:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/04/02 23:31:41 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_line(char *stack)
{
	char	*line;
	int		i;

	if (!*stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*ptr;
	int		i;

	ptr = ft_strchr(stack, '\n');
	if (!ptr)
	{
		free(stack);
		return (NULL);
	}
	ptr++;
	aux = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (*ptr != '\0')
	{
		aux[i] = *ptr;
		i++;
		ptr++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*ft_reader(int fd, char *stack)
{
	char	*buffer;
	int		reader;

	if (!stack)
				stack = calloc(1, sizeof(char));
	if (!stack)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (!(ft_strchr(stack, '\n')) && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (free(stack), free(buffer), NULL);
		buffer[reader] = '\0';
		if (!stack)
			stack = ft_strdup(buffer);
		else
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[4096];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stack[fd])
		{
			free(stack[fd]);
			stack[fd] = NULL;
		}
		return (NULL);
	}
	stack[fd] = ft_reader(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	line = make_line(stack[fd]);
	stack[fd] = update_stack(stack[fd]);
	return (line);
}
