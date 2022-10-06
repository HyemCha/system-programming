#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	struct stat statbuf;

	chmod(argv[1], S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);

	stat(argv[1], &statbuf);
	printf("1. Mode = %o\n", (unsigned int)statbuf.st_mode);

	statbuf.st_mode |= S_IWGRP;
	statbuf.st_mode &= ~(S_IROTH);

	chmod(argv[1], statbuf.st_mode);

	stat(argv[1], &statbuf);
	printf("2. Mode = %o\n", (unsigned int)statbuf.st_mode);
}
