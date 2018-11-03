#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct dirent *direntry;
	struct stat buffer;
	int total = 0;

	DIR *directory;

	// // testing printfs
	// printf("argc: %d\n", argc);
	// printf("argv[0]: %s\n", argv[0]);
	// printf("argv[1]: %s\n", argv[1]);

	if(argc > 1){
		directory = opendir(argv[1]);
	}
	else{
		char dir_name[100];
		printf("Enter a directory: \n");
		scanf("%s", dir_name);
		directory = opendir(dir_name);
	}

	/* lines 17 to 25 work but if the thing entered is not ".", it thinks all the
			items in the directory are other directories. IDK why */

	if (!directory)
	{
		printf("Directory given does not exist! ERORR! \n");
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
