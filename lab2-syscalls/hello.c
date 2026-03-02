#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen
#include <unistd.h> // for syscall function
#include <sys/syscall.h> // for syscal constants like SYS_write 

static const char* LIB_NAME = "./libhello.so";
static void greeting_from_lib();

static void greeting_wrapped_syscall() 
{
}

void greeting_write_syscall()
{
    const char* msg = "Hi, world!\n";
    int written = write(1, msg, strlen(msg));
    if (written == -1) {
        // print description of errno after my message
        perror("ERROR (greeting_wrapped_syscall())");
    }
   
}   

void get_str(const char str[])
{
}

int main(void)
{
	greeting_from_lib();
    greeting_write_syscall();         // task 1.1.2
    greeting_wrapped_syscall(); // task 1.1.3
}










static void greeting_from_lib()
{
	char *error;
	
    void *handle = dlopen(LIB_NAME, RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);  
    }

    dlerror();    /* Clear any existing error */

	void (*hello_from_dyn_runtime_lib) (void) = dlsym(handle, "hello_from_dyn_runtime_lib");
    error = dlerror();
    if (error) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    hello_from_dyn_runtime_lib(); 

    dlclose(handle);
}


