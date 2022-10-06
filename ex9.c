#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	 char *cwd;

	 cwd = errCwd(NULL, BUFSIZ);
	 printf("1.Current Directory:%s\n", cwd);

	 chdir("byte");

	 cwd = errCwd(NULL, BUFSIZ);
	 printf("2.Current Directory:%s\n", cwd);

	 free(cwd);
}

char errCwd(char *buf, size_t size){
	if(getcwd(buf, size) == NULL){
		perror("getcwd");
		exit(1);
	}
	return getcwd(buf, size);
}


