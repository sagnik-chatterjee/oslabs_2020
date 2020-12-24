#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	execl("/bin/wc", "wc", "-l", "foo", (char*)0);
	return 0;
}