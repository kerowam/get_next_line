/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:15:43 by gfredes-          #+#    #+#             */
/*   Updated: 2023/03/29 22:18:17 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	count;

	count = 0;
	if ((char)c == '\0')
	{
		while (s[count] != '\0')
			count++;
		return ((char *)&s[count]);
	}
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
		{
			return ((char *)&s[count]);
		}
		count++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (*s != '\0')
	{
		s++;
		c++;
	}
	return (c);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			len;
	unsigned char	*dst;

	len = 0;
	ptr = malloc(len * size);
	if (!ptr)
		return (0);
	dst = (unsigned char *) ptr;
	while (len < size)
	{	
		dst[len] = (unsigned char) 0;
		count++;
	}
	return (ptr);
}
