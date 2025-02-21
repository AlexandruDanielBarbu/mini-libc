// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	int long long result = (int long long)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (result < 0)
	{
		return NULL;
	}

	mem_list_add((void*)result, size);
	return (void*)result;
}

#define ILL int long long
void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	int prot = PROT_READ | PROT_WRITE;
	int flag = MAP_ANONYMOUS | MAP_PRIVATE;
	ILL result = (ILL)mmap(NULL, nmemb * size, prot, flag, -1, 0);

	if (result < 0)
	{
		return NULL;
	}

	memset((void*)result, 0, nmemb * size);

	mem_list_add((void*)result, size * nmemb);
	return (void*)result;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr != NULL)
	{
		struct mem_list *target = mem_list_find(ptr);

		if (target != NULL)
		{
			munmap(ptr, target->len);
			mem_list_del(ptr);
		}
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *rez = NULL;
	rez = malloc(size);

	if (rez != NULL)
	{
		memcpy(rez, ptr, size);
		free(ptr);
		return rez;
	}

	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *rez = NULL;
	rez = malloc(size * nmemb);

	if (rez != NULL)
	{
		memcpy(rez, ptr, size * nmemb);
		free(ptr);
		return rez;
	}

	return NULL;
}
