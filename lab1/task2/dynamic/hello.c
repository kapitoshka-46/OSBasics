#include <stdio.h>

void hello_from_dynamic_lib();

int main() {
	puts("Hello, world");

	hello_from_dynamic_lib();
	return 0;
}
