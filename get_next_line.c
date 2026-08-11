#include "get_next_line.h"
#include <stdio.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dest || !src || n == 0)
		return (dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static size_t	get_nl_idx(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*process_str(t_list **list, char *line)
{
	t_list	*head;
	char	*tmp;

	head = *list;
	line = malloc(sizeof(char) * (len(list) + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (*list && !find_chr((*list)->content))
	{
		ft_strncat(line, (*list)->content, (size_t)-1);
		pop_front(list, 1);
	}
	if (*list && find_chr((*list)->content))
	{
		head = *list;
		ft_strncat(line, head->content, get_nl_idx(head->content));
		tmp = ft_strdup(head->content + get_nl_idx(head->content));
		free(head->content);
		head->content = tmp;
		if (head->content && head->content[0] == '\0')
			pop_front(list, 1);
	}
	return (line);
}

static char	*read_file(t_list **list, char *buffer, char *line, int fd)
{
	ssize_t	nbyte;
	t_list	*head;

	nbyte = read(fd, buffer, BUFFER_SIZE);
	while (nbyte > 0)
	{
		buffer[nbyte] = '\0';
		if (!*list)
			*list = node_init(list, buffer);
		else
		{
			head = *list;
			while (head->next != NULL)
				head = head->next;
			head->next = node_init(list, buffer);
		}
		if (find_chr(buffer))
			break ;
		nbyte = read(fd, buffer, BUFFER_SIZE);
	}
	return (process_str(list, line));
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (pop_front(&head, 2), NULL);
	line = NULL;
	buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_file(&head, buffer, line, fd);
	free(buffer);
	if (!line && head)
		pop_front(&head, 2);
	return (line);
}
