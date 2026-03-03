#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>      // for syscall function
#include <sys/syscall.h> // for syscal constants like SYS_write 

const char* LIB_NAME = "./libhello.so";



void hello_simple() {
    printf("hello, world\n");
}

void hello_libc_write() {
    const char msg[] = "hello_libc_write: hello, world\n";
    int written = write(1, msg, sizeof(msg) - 1);
    if (written == -1) {
        perror("ERROR (hello_libc_write)");
    }
}   

void hello_syscall() {
    const char msg[] = "hello_syscall: hello, world\n";
    int written = syscall(SYS_write, 1, msg, sizeof(msg) - 1);
    if (written == -1) {
        perror("ERROR (hello_syscall");
    }
}

int main(void) {
	hello_simple();
    hello_libc_write();     // task 1.1.2
    hello_syscall();        // task 1.1.3                
}