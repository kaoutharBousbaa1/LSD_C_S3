#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>

int x = _BUFFERSIZE_;
static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}
static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(s, line, ret, fd));
}
int main(int argc, int* argv[])
{	
  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  return (0);
}
