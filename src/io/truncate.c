// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYSTEM_TRUNCATE 76
int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int result = syscall(SYSTEM_TRUNCATE, path, length);

	if (result >= 0)
	{
		return 0;
	}

	errno = -result;
	return -1;
}
