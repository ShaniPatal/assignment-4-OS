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
   int fd;
    char data[1024];

    // fills the data array with 7s
    memset(data, 7, 1024);
    fd = open("sanity_file", O_CREATE | O_RDWR);
    for(int i = 0; i < 1024*10; i++){
        write(fd, data, sizeof(data));
        if (i == 11)
            printf("Finished writing 12KB (direct)\n");
        if (i == 267)
            printf("Finished writing 268KB (single direct)\n");
    }
    printf("Finished writing 10MB\ntest finished\n");
}

void
task3_test(void){
    int fd;
    char data[1024];

    // fills the data array with 7s
    fd = open("sanity", O_CREATE | O_RDWR);
    write(fd, "banana", sizeof(data));
}

int main(int argc, char* argv[]){
	printf("**Sanity Tests**\n");
	task3_test();
	exit(1);
	return 0;
}

