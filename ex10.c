#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argv[1] == NULL){
		printf("파일 이름이 입력되지 않았습니다.\n");
		exit(1);
	}
	if(rmdir(argv[1]) == -1){
		perror(argv[1]);
		exit(1);
	}
	printf("\'%s\' 디렉터리가 비어있습니다.\n", argv[1]);
}
