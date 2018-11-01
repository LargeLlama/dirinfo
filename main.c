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

	while((direntry = readdir(directory)))
	{
		stat(direntry->d_name, &buffer);
		if (S_ISREG(buffer.st_mode))
		{
			int total = total + buffer.st_size;
			printf("File name: %s\nFile size: %ldB\n", direntry->d_name, buffer.st_size);  
		}
	}
	printf("total size of files: %d\n", total);
	return 0;
}
