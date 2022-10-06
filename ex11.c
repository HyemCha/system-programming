#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	if(mkdir(argv[1], 0755) == -1){
		perror(argv[1]);
		exit(1);
	}

	char *cwd;

	cwd = getcwd(NULL, BUFSIZ);
	printf("현재 디렉터리 : %s\n", cwd);

	chdir(argv[1]);

	cwd = getcwd(NULL, BUFSIZ);
	printf("현재 디렉터리 : %s\n", cwd);

	free(cwd);
}
