#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>

int x = BUFSIZ;
int st_len(char *s)
{
	char* temp;
	int i = 0;
	if(s == NULL)
		return 0;
	temp = s;
	while(temp[i] != '\0')
	{
		temp = temp + i;
		i++;
	}
	return (i+1);
}
char 	*ch_join(char *s1, char *s2)
{
	char* temp;
	int i, j;
	if(!s1 || !s2)
		return NULL;
	temp = malloc(((st_len(s1) + st_len(s2) + 1) * sizeof(char)));
	if(!temp)
		return NULL;
	i = 0;
	j = 0;
	while(i < st_len(s1))
	{
		temp[i] = s1[i];
		i++;
	}
	while(j < st_len(s2))
	{
		temp[j + i] = s2[j];
		j++;
	}
	return temp;
}
void *stcpy(void *s1, void *s2, int n)
{
	char	*temp1;
	char	*temp2;
	temp1 = (char*)s1;
	temp2 = (char*)s2;
	while(n--)
		temp2[n] = temp1[n];
	return temp1;
}
char* get_line(char *c)
{
	char* line;
	int i;
	char* tab;
	if(c = NULL)
		return NULL;
	i = 0;
	while(c[i] != '\n')
		i++;
	i++;
	tab = (char*)malloc(sizeof(char) * (i+1));
	tab = stcpy(tab, c, i);
	tab[i] = '\0';
	return tab;
}
char 		*get_next_line(int fd)
{
	char 			buff[BUFSIZ];
	char			*line;
	static char		*c;
	int 			byte;
	if(BUFSIZ <= 0 || fd < 0)
		return NULL;
	byte = 1;
	while(byte > 0)
	{
		byte = read(fd, buff, BUFSIZ);
		if(byte == -1)
			return NULL;
		else if(byte == 0)
		{
			buff[byte] = '\0';
			break;
		}
		c = ch_join(c, buff);	
	}
	line = get_line(c);
	return line;
}
int main(int argc, int* argv[])
{	
	int fd = open("newfile.txt", O_RDONLY);
	char* line = NULL;	
	line = get_next_line(fd);
	while(line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return 0;
}
