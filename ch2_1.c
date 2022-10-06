#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	if(mkdir(argv[1], atoi(argv[2])) == -1){
		perror(argv[1]);
		exit(1);
	}
}
