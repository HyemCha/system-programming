#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int fd;
	struct stat statbuf;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror(argv[1]);
		exit(1);
	}

	fstat(fd, &statbuf);

	printf("Inode = %d\n", (int)statbuf.st_ino);
	printf("UID = %d\n", (int)statbuf.st_uid);
	close(fd);
}
