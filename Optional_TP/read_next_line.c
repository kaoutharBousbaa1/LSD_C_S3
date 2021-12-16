#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>

int x = BUFSIZ;
int st_len(char *s)
{
	int i;
	i = 0;
	if(!s)
		return 0;
	while(s[i] != '\0')
		i++;
	return i;
}
char 	*ch_join(char *s1, char *s2)
{
	char* temp = NULL;
	int i, j;
	if(!s1 || !s2)
	{
		printf("Test");
		return NULL;
	}
	temp = malloc((st_len(s1) + st_len(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while(s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while(s2[j] != '\0')
	{
		temp[j + i] = s2[j];
		j++;
	}
	temp[j+i] = '\0';
	return temp;
}
void *stcpy(void *s1, void *s2, int n, int k)
{
	char	*temp1;
	char	*temp2;
	temp1 = (char*)s1;
	temp2 = (char*)s2;
	while(k < n)
	{
		temp1[k] = temp2[k];
		k++;
	}
	return temp1;
}
char* get_line(char *c)
{
	char* line;
	static int i;
	int j = 0;
	char* tab;
	j = i;
	if(c == NULL)
		return NULL;
	while(c[i] != '\n')
		i++;
	i++;
	tab = (char*)malloc(sizeof(char) * ((i+1)-j));
	int k = 0;
	while(k < i-j)
	{
		tab[k] = c[j+k];
		k++;
	}
	//tab = stcpy(tab, c, i, j-i);
	tab[i-j] = '\0';
	//printf("%s", tab);
	return tab;
}
char 		*get_next_line(int fd)
{
	char 			buff[BUFSIZ];
	char			*line;
	char		*c;
	int 			byte;
	if(BUFSIZ <= 0 || fd < 0)
		return NULL;
	byte = 1;
	while(byte != 0)
	{
		byte = read(fd, buff, BUFSIZ);
		if(byte == -1)
			return NULL;
		else if(byte == 0)
		{
			buff[byte] = '\0';
			break;
		}
		if(c == NULL)
			c = buff;
		else
			c = ch_join(c, buff);	
	}
	//printf("%s", c);
	line = get_line(c);
	return line;
}
int main(int argc, int* argv[])
{	
	int fd = open("newfile.txt", O_RDONLY);
	char* line;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	/*do
	{
		line = get_next_line(fd);
		printf("%s", line);
	}while(line != NULL);*/
	return 0;
}
