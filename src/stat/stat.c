// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

#define SYSCALL_STAT 4
int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int result = syscall(SYSCALL_STAT, path, buf);

	if (result >= 0)
	{
		return 0;
	}

	errno = -result;
	return -1;
}
