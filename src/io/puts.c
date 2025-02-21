// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define STDOUT 1
int puts(const char *s)
{
	/* TODO: Implement puts() without a :)) */
	int check1 = write(STDOUT, s, strlen(s));

    if (check1 >= 0)
    {
        int check2 = write(STDOUT, "\n\0", 2);
        if (check2 >= 0)
        {
            return 0;
        }
    }

	return -1;
}
