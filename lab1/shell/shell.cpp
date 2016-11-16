#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void output(char* str) {
	printf(": ");
	puts(str);
}

void error(char* type, char* msg) {
	printf("! error (%s): %s\n", type, msg);
}

int main(int argc, char const *argv[])
{
	char dir[256];
	char input[256];
	char args[256];
	while(true) {
		getcwd(dir, 256);
		printf("%s> ", dir);
		gets(input);

		/* cd
		 *****/
		if(strcmp(input, "cd") == 0 || strncmp(input, "cd ", 3) == 0) {
			if(strlen(input) == 2)
				error("syntax", "cd [path]");
			else {
				strcpy(args, input + 3);
				if(strchr(args, ' ') != NULL) {
					error("syntax", "cd [path]");
				} else {
					chdir(args);
				}
			}
		/* dir
		 ******/
		} else if(strcmp(input, "dir") == 0 || strncmp(input, "dir ", 4) == 0) {
			if(strlen(input) > 3)
				error("syntax", "dir");
			else {
				DIR* dirp = opendir(".");
				dirent entry;
				dirent* result;
				output(".");
				output("..");
				while(readdir_r(dirp, &entry, &result) == 0 && result != NULL) {
					if(strcmp(entry.d_name, ".") == 0 || strcmp(entry.d_name, "..") == 0)
						continue;
					output(entry.d_name);
				}
				closedir (dirp);
			}
		/* execute
		 **********/
		} else {
			system(input);
		}
	}
	return 0;
}