#include "get_next_line.h"

t_list	*node_init(t_list **list, char *buffer)
{
	t_list	*node;
	(void)list;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = ft_strdup(buffer);
	node->next = NULL;
	return (node);
}

void	pop_front(t_list **list, int mode)
{
	t_list	*head;
	t_list *next;

	head = NULL;
	next = NULL;
	if (mode == 2)
	{
		head = (*list);
		while (head != NULL)
		{
			next = head->next;
			free(head->content);
			free(head);
			head = next;
		}
		return ;
	}
	next = (*list)->next;
	free((*list)->content);
	free((*list));
	*list = next;
}

int	len(t_list **list)
{
	t_list *head;
	size_t	i;
	size_t	size;

	if (!list)
		return (0);
	head = *list;
	i = 0;
	size = 0;
	while (head != NULL)
	{
		i = 0;
		while (head->content[i])
		{
			size++;
			i++;
		}
		head = head->next;
	}
	return (size);
}

int	find_chr(char *content)
{
	size_t	i;

	if (!content)
		return (0);
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
