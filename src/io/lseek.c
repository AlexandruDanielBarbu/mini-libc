// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYSTEM_LSEEK 8
off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int result = syscall(SYSTEM_LSEEK, fd, offset, whence);

	if (result >= 0)
	{
		return result;
	}

	errno = -result;
	return -1;
}
