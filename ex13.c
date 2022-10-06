#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
	DIR *dp;
	struct dirent *dent;
	long loc;

	dp = opendir(".");

	printf("시작 지점 : %ld\n", telldir(dp));
	while(dent = readdir(dp)){
		printf("Read : %s -> ", dent->d_name);
		printf("현재 위치 : %ld\n", telldir(dp));
	}

	printf("-------------디렉터리 위치 되돌리기--------------\n");

	rewinddir(dp);

	readdir(dp);
	readdir(dp);
	readdir(dp);
	loc = telldir(dp);
	seekdir(dp, loc);
	printf("현재 위치 : %ld\n", telldir(dp));

	dent = readdir(dp);
	printf("Read : %s \n", dent->d_name);

	closedir(dp);
}
