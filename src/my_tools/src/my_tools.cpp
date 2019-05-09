#include <stdio.h>
#include <execinfo.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_tools/my_tools.h"

namespace my_tools
{
void my_test(void)
{
	printf("my_tools::my_test!\n");
}

#define BT_BUF_SIZE 100

void printBackTrace(void)
{
	int j, nptrs;
	void *buffer[BT_BUF_SIZE];
	char **strings;

	nptrs = backtrace(buffer, BT_BUF_SIZE);
	printf("backtrace() returned %d addresses\n", nptrs);

	/* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
	*               would produce similar output to the following: */

	strings = backtrace_symbols(buffer, nptrs);
	if (strings == NULL) {
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	for (j = 0; j < nptrs; j++)
		printf("%s\n", strings[j]);
	free(strings);
}

}
