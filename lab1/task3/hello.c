#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static const char* LIB_NAME = "./libhello.so";

int main(void) {
    char *error;

    void *handle = dlopen(LIB_NAME, RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();    /* Clear any existing error */

	void (*hello_from_dyn_runtime_lib) (void) = dlsym(handle, "hello_from_dyn_runtime_lib");
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    hello_from_dyn_runtime_lib();

    dlclose(handle);

    exit(EXIT_SUCCESS);
}
