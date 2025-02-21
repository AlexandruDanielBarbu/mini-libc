// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYSCALL_FSTAT 5
int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int result = syscall(SYSCALL_FSTAT, fd, st);

	if (result >= 0)
	{
		return 0;
	}

	errno = -result;
	return -1;
}
