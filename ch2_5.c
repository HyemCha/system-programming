#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	if(rename(argv[1], argv[2]) == -1){
		perror("rename");
		exit(1);
	}
}
