#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	if(argv[1] == NULL){
		printf("파일 이름이 입력되지 않았습니다.\n");
		exit(1);
	}

	int fd;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		printf("\'%s\' 파일이 존재하지 않습니다.\n", argv[1]);
		exit(1);
	}
	printf("\'%s\' 파일이 존재합니다.\n", argv[1]);
	
	close(fd);
}
