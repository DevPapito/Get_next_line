#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

t_list	*node_init(t_list **list, char *buffer);
void	pop_front(t_list **list, int mode);
int		find_chr(char *content);
int		len(t_list **list);
char	*ft_strdup(char *content);

#endif
