// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list arguments_list;
	mode_t mode = 0;

	if (flags & O_CREAT)
	{
		va_start(arguments_list, flags);
		mode = va_arg(arguments_list, mode_t);
		va_end(arguments_list);
	}

	int result;

	if (flags & O_CREAT)
	{
		result = syscall(2, filename, flags, mode);
	} else{
		result = syscall(2, filename, flags);
	}

	if (result >= 0) return result;

	errno = -result;
	return -1;
}
