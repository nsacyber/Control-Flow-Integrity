#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo();

int main(int argc, char *argv[]) {
void (*fptr)();
char localbuf[16];

	if (argc != 3) {
		printf("Usage: %s length data\n", argv[0]);
		exit (-1);
	}
/* corrupt main() stack frame */
	fptr = foo;
	memcpy(localbuf, argv[2], atoi(argv[1]));
	(*fptr)();
}

void foo() {
	printf("you are in foo\n");
}
