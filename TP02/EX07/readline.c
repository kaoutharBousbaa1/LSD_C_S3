#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>

/*char* get_next_line(int fd)
{
	char* line;
	int n_bytes;
	void* BUFFER_SIZE[20];
	if(n_bytes = read(fd, BUFFER_SIZE, 10))
	{
		if (line == NULL) 
            	{   
              		printf("Error! Could not open file\n"); )
			return NULL;
            	} 
		while(*line == ' ' || *line =='\t')
			line++;
		return line;
	}
	else
		return NULL;
*/
char* get_next_line(int fd)
{
	char* cr = malloc(sizeof(char)*50);
	int x = read(fd, cr, 50);
	return cr;
}
int main(int argc, int* argv[])
{	
	/*FILE* filename = "file.txt";
	FILE* file = fopen(filename, "r");
	int fd = open("file.txt", O_RDONLY);
	char* line;
	while(line != "\0")
		line = get_next_line(fd);
	fclose(file);
	return 0;*/
	int fd = open("newfile.txt", O_RDONLY);
	char* rt = get_next_line(fd);
	printf("Test %s", rt);
	
	return 0;
}
