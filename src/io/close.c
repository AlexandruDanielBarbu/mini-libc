// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

#define SYSTEM_CLOSE 3
int close(int fd)
{
	/* TODO: Implement close(). */
	int result = syscall(SYSTEM_CLOSE, fd);

	if (result >= 0) return 0;

	errno = -result;
	return -1;
}
