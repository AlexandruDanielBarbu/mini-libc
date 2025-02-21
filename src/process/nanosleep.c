// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#define SYSCALL_NANOSLEEP 35
int nanosleep(const struct timespec *duration, struct timespec *rem)
{
    int result = syscall(SYSCALL_NANOSLEEP, duration, rem);

    if (result >= 0)
    {
        return 0;
    }

    errno = -result;
	return -1;
}
