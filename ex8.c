#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char *cwd;

	cwd = getcwd(NULL, BUFSIZ);
	printf("현재 디렉터리 : %s\n", cwd);

	chdir("byte");
	cwd = getcwd(NULL, BUFSIZ);
	printf("현재 디렉터리 : %s\n", cwd);

	if(mkdir("han",0755) == -1){
		perror("han");
		exit(1);
	}

	chdir("..");
	cwd = getcwd(NULL, BUFSIZ);
	printf("현재 디렉터리 : %s\n", cwd);
}
