#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	char *fname = argv[1], *dname = argv[2];
	char *cwd = NULL;

	if(argv[2] == NULL){
		printf("There is no Directory name argument\n");
		exit(1);
	}

	int fd, fd_sub;
	// 디렉터리 검색
	fd = open(argv[2], O_RDONLY);
	
	// 디렉터리 이동
	fchdir(fd);
	cwd = getcwd(NULL, BUFSIZ);

	if(fd == -1){
		printf("Directory \'%s\' doesn't exist.\n", argv[2]);
	       exit(1);	
	}

	// 파일 검색
	fd_sub = open(argv[1], O_RDONLY);
	if(fd_sub == -1){
		printf("\'%s\' doesn't exist in Directory \'%s\'\n", argv[1], cwd);
		close(fd);
		close(fd_sub);
		free(cwd);
	 	exit(1);	
	}

	printf("\'%s\' exist in Directory \'%s\'\n", fname, cwd);
	close(fd);
	close(fd_sub);
	free(cwd);
}
