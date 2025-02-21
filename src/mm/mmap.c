// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

#define SYSTEM_MMAP 9
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	int long long rez = syscall(SYSTEM_MMAP, addr, length, prot, flags, fd, offset);

	if (rez < 0)
	{
		errno = -rez;
		return MAP_FAILED;
	}

	return (void*) rez;
}

#define SYSCALL_MREMAP 25
void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	int long long rez = syscall(SYSCALL_MREMAP, old_address, old_size, new_size, flags);

	if (rez < 0)
	{
		errno = -rez;
		return MAP_FAILED;
	}

	return (void*)rez;
}

#define SYSCALL_MUNMAP 11
int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int result = syscall(SYSCALL_MUNMAP, addr, length);
	if (result >=0)
	{
		return 0;
	}

	errno = -result;
	return -1;
}
