#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>

char* get_next_line(int fd)
{
	char* cr = malloc(sizeof(char)*300);
	int x = read(fd, cr, 300);
	return cr;
}
int main(int argc, int* argv[])
{	
	int fd = open("newfile.txt", O_RDONLY);
	char* rt = get_next_line(fd);
	printf("Test %s", rt);
	
	return 0;
}
