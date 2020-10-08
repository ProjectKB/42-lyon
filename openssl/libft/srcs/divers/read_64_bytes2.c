#include "libft.h"

static t_list	*ft_find_fd(t_list **list, int fd)
{
	t_list	*list_temp;

	list_temp = *list;
	while (list_temp && list_temp->content_size != (size_t)fd)
		list_temp = list_temp->next;
	if (list_temp == NULL)
	{
		list_temp = ft_lstnew(NULL, 0);
		list_temp->content_size = (size_t)fd;
		ft_lstadd(list, list_temp);
	}
	return (list_temp);
}

static int		ft_read_fd(int fd, t_list *list)
{
	int		ret;
	char	*buff;
	char	*temp;

	ret = 0;
	if (!(buff = ft_strnew(64)))
		return (-1);
	if ((ret = read(fd, buff, 64)))
	{
		
		buff[ret] = '\0';
		if (!list->content)
			list->content = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(list->content, buff);
			ft_memdel(&list->content);
			list->content = temp;
		}
	}
	free(buff);
	return (ret);
}

static int		free_lst(t_list *list)
{
	t_list *tmp;

	tmp = list->next;
	free(list);
	list = tmp;
	return (0);
}

int				read_64_bytes2(const int fd, unsigned char **line)
{
	static t_list	*p_list = NULL;
	t_list			*list;
	int				ret;

	ret = 1;
	if (fd < 0 || line == NULL || (read(fd, NULL, 0) < 0))
		return (-1);
	list = ft_find_fd(&p_list, fd);
	ret = ft_read_fd(fd, list);
	*line = list->content;
	if (*line == NULL || (ret < 64 && ft_strlen(list->content) == 0))
		return (free_lst(list));
	ft_memdel(&list->content);
	return (ret);
}