#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>

int x = _BUFFERSIZE_;
char* get_next_line(int fd)
{
	char* cr = malloc(sizeof(char)*_BUFFERSIZE_);
	int x = read(fd, cr, _BUFFERSIZE_);
	if (cr == NULL) 
        {   
		printf("Error! Could not open file.\n"); 
		return NULL;
	} 
	return cr;
}
int main(int argc, int* argv[])
{	
	int fd = open("newfile.txt", O_RDONLY);
	if(!fd)
	{
		printf("Error! The file doesn't exist.\n");
		exit(1);
	}
	char* rt = get_next_line(fd);
	printf("%s", rt);
	
	return 0;
}
