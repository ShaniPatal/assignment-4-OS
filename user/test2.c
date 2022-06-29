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


int
main(int argc, char *argv[])
{   
    if (*argv[1] == 'r'){
        char buf[MAXPATH];
        if (readlink(argv[2], buf, MAXPATH) < 0){
            fprintf(2, "error\n");
            exit(1);
        }
        fprintf(1, "buf is %s\n", buf);
        exit(0);
    }
    return 0;
}
