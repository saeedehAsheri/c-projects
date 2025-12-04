/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:35:01 by sasheri           #+#    #+#             */
/*   Updated: 2025/11/04 13:54:16 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_and_join(int fd, char **buf, char *join, ssize_t *r_bytes)
{
	char	*tmp;

	*r_bytes = read(fd, join, BUFFER_SIZE);
	if (*r_bytes < 0)
		return (0);
	if (*r_bytes == 0)
		return (1);
	join[*r_bytes] = '\0';
	tmp = ft_strjoin(*buf, join);
	if (!tmp)
		return (0);
	free(*buf);
	*buf = tmp;
	return (1);
}

static char	*read_file(int fd, char *buf)
{
	char	*join;
	ssize_t	r_bytes;

	if (!buf)
	{
		buf = (char *)malloc(1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	join = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!join)
		return (free(buf), NULL);
	r_bytes = 1;
	while (r_bytes > 0 && !ft_strchr(buf, '\n'))
	{
		if (!read_and_join(fd, &buf, join, &r_bytes))
			return (free(join), free(buf), NULL);
	}
	free(join);
	return (buf);
}

char	*fetch_line(char *buf)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*till_n;

	if (!buf || !buf[0])
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	len = i + (buf[i] == '\n');
	till_n = (char *)malloc(len + 1);
	if (!till_n)
		return (NULL);
	j = 0;
	while (j < len)
	{
		till_n[j] = buf[j];
		j++;
	}
	till_n[j] = '\0';
	return (till_n);
}

static char	*save_after_n(char *buf)
{
	size_t	i;
	size_t	j;
	size_t	new_len;
	char	*after_n;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	i++;
	new_len = ft_strlen(buf) - i;
	after_n = (char *)malloc(new_len + 1);
	if (!after_n)
		return (free(buf), NULL);
	j = 0;
	while (buf[i])
		after_n[j++] = buf[i++];
	after_n[j] = '\0';
	free(buf);
	return (after_n);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_file(fd, buf);
	if (!buf)
		return (NULL);
	line = fetch_line(buf);
	if (!line)
		return (free(buf), buf = NULL, NULL);
	buf = save_after_n(buf);
	return (line);
}

/*#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) 
    { 
        printf("%s", line); 
        free(line); 
    }
    close(fd);
    return 0;
}*/