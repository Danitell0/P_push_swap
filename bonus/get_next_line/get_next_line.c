/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:53:16 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/20 14:54:23 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	char		*tmp;

	result = NULL;
	if (fd < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (buffer == NULL)
			return (NULL);
	}
	if (!fill_buffer(&buffer, fd))
	{
		free(buffer);
		return (NULL);
	}
	result = extract_line(buffer);
	tmp = buffer;
	buffer = trim_buffer(tmp);
	free(tmp);
	return (result);
}

char	*extract_line(char	*buffer)
{
	char	*line;
	char	*new_line;
	size_t	len;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	line = ft_strchr(buffer, '\n');
	if (line == NULL)
		len = ft_strlen(buffer);
	else
		len = line - buffer + 1;
	new_line = ft_calloc(len + 1, sizeof(char));
	if (new_line == NULL)
		return (NULL);
	ft_strncpy(new_line, buffer, len);
	return (new_line);
}

char	*trim_buffer(char *buffer)
{
	char	*new_buffer;
	char	*tmp;

	if (!buffer || buffer[0] == '\0' || !ft_strchr(buffer, '\n'))
		return (NULL);
	tmp = ft_strchr(buffer, '\n') + 1;
	new_buffer = ft_calloc(ft_strlen(tmp) + 1, sizeof(char));
	if (new_buffer == NULL)
		return (NULL);
	new_buffer = ft_strncpy(new_buffer, tmp, ft_strlen(tmp));
	return (new_buffer);
}

int	fill_buffer(char **buffer, int fd)
{
	char	*tmp;
	char	*tmp_buffer;
	ssize_t	bytes;

	bytes = 1;
	tmp = NULL;
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tmp_buffer == NULL)
		return (0);
	while (!ft_strchr(*buffer, '\n') && bytes > 0)
	{
		tmp = *buffer;
		ft_bzero(tmp_buffer, BUFFER_SIZE);
		bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		*buffer = ft_strjoin(tmp, tmp_buffer);
		if (*buffer == NULL)
			free(tmp_buffer);
		free(tmp);
	}
	free (tmp_buffer);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total_len;
	int		i;

	if (!s1)
		s1 = "";
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(total_len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	return (str);
}
