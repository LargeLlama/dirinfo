#include <stdio.h> 
#include <dirent.h>
#include <sys/stat.h>

int main()
{
	struct dirent *direntry;
	struct stat buffer;
	int total = 0;

	DIR *directory = opendir(".");
	if (!directory)
	{
		printf("Directory given does not exist! ERORR!");
		return 1;
	}
	printf("FORMAT\nTYPE : NAME : SIZE\n");

	while((direntry = readdir(directory)))
	{
		stat(direntry->d_name, &buffer);
		if (S_ISREG(buffer.st_mode))
		{
			total += buffer.st_size;
			printf("FILE : %s : %ldB\n", direntry->d_name, buffer.st_size);  
		}
		if(S_ISDIR(buffer.st_mode))
		{
			printf("DIR  : %s : %ldB\n", direntry->d_name, buffer.st_size);
		}
	}
	printf("total size of files: %d\n", total);
	return 0;
}
