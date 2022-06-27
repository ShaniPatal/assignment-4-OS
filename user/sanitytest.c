#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

/* Sanity test for task 1*/
void
t1Test(void){
	printf("running sanity test for task1\n");

	int fd;
	char data[1024];
	int numBytes;	//just to check the length
	// fills the data array with 7s
	memset(data, 7, 1024);

	fd = open("task1Sanity", O_CREATE | O_RDWR);
	numBytes = fd; //set initial position
	
	for(int i = 0; i < 1024 * 10; i++){
		numBytes += write(fd, data, sizeof(data));
		if (i == 11)
			printf("Finished writing 12KB (direct)\n");
		if (i == 267)
			printf("Finished writing 268KB (single direct)\n");
	}
	printf("Finished writing 10MB\ntest finished\n");
}

int main(int argc, char* argv[]){
	printf("**Sanity Tests**\n");
	t1Test();
	exit(1);
	return 0;
}
