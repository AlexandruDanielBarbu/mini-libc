// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYSTEM_FTRUNC 77
int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int result = syscall(SYSTEM_FTRUNC, fd, length);

	if (result >= 0)
	{
		return 0;
	}

	errno = -result;
	return -1;
}
