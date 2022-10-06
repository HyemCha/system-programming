#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fd, n;
       	char buf[50];

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror(argv[1]);
		exit(1);	
	}
	
	while((n = read(fd, buf, 50)) > 0){
		printf("%s\n", buf);
	}
	close(fd);
	
}
