#include <stdio.h>

extern void hello_from_static_lib(void);

int main() {
	puts("Hello, world");

	hello_from_static_lib();
	return 0;
}
