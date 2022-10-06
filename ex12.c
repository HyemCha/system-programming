#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
	DIR *dp;
	struct dirent *dent;

	dp = opendir(".");

	while(dent = readdir(dp)){
		char *dname = (dent->d_name);
		printf("%s ",dname);
		if(dname == "." || (*dent).d_name == ".."){
			printf(" nonono ");
		}
		printf("%s  ", dent->d_name);
	}
	printf("\n");
	closedir(dp);
}
