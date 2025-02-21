// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec sec, remainder;

	sec.tv_sec = seconds;
	sec.tv_nsec = 0;

	if (nanosleep(&sec, &remainder) != 1)
	{
		return remainder.tv_sec;
	}

	return 0;
}
