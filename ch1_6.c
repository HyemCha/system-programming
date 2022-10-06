#include <stdio.h>

int main(int argc, char *argv[]){
	int n;

	printf("argc = %d\n", argc);
	for(n=0; n<argc; n++){
		printf("agv[%d] = %s\n", n, argv[n]);
	}
}
