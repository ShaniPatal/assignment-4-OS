#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

//
// Tests xv6 system calls.  usertests without arguments runs them all
// and usertests <name> runs <name> test. The test runner creates for
// each test a process and based on the exit status of the process,
// the test runner reports "OK" or "FAILED".  Some tests result in
// kernel printing usertrap messages, which can be ignored if test
// prints "OK".
//

#define NUM 100

int
main(int argc, char *argv[])
{
    char buf[NUM];
    for (int i = 0; i < NUM; i++){
        buf[i] = 'x';
    }

    /* char b = 'x'; */
    

    int fd;
    if ((fd = open("t", O_CREATE | O_RDWR)) < 0){
        fprintf(2, "cannot open file\n");
        exit(1);
    }
    fprintf(1, "successful open\n");

    for (int i = 0; i < 1; i++){
        if (write(fd, &buf, NUM) != NUM){
            fprintf(2, "can't write char\n");
            exit(1);
        }
    }
    /* if (write(fd, buf, BSIZE) < 1){
        fprintf(2, "can't write char\n");
        exit(1);
    } */
        
    close(fd);
    exit(0);
}
