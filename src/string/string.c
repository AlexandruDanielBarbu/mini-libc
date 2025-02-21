// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *c = destination;
	const char *d = source;

	while (*d != '\0')
	{
		*c = *d;
		c++;
		d++;
	}

	*c = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t offset = 0;

	while (offset != len)
	{
		*(destination + offset) = *(source + offset);
		offset++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *c = destination;

	while (*c != '\0')
	{
		c++;
	}

	const char *d = source;

	while (*d != '\0')
	{
		*c = *d;
		c++;
		d++;
	}

	*c = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *c = destination;

	while (*c != '\0')
	{
		c++;
	}

	size_t offset = 0;

	while (offset != len)
	{
		*(c + offset) = *(source + offset);
		offset++;
	}

	*(c + offset) = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	const char *s1 = str1;
	const char *s2 = str2;

	while (((*s1) - (*s2) == 0) && (*s1 != '\0') && (*s2 != '\0'))
	{
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 != '\0')
	{
		return -1;
	} else {
		if (*s1 != '\0' && *s2 == '\0')
		{
			return 1;
		} else {
			return ((*s1) - (*s2));
		}
	}
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	const char *s1 = str1;
	const char *s2 = str2;

	size_t offset = 0;

	while (((*s1) - (*s2) == 0) && (*s1 != '\0') && (*s2 != '\0'))
	{
		s1++;
		s2++;
		offset++;

		if (offset == len)
		{
			s1--;
			s2--;
			break;
		}
	}

	if (*s1 == '\0' && *s2 != '\0')
	{
		return -1;
	} else {
		if (*s1 != '\0' && *s2 == '\0')
		{
			return 1;
		} else {
			return ((*s1) - (*s2));
		}
	}

	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	const char *d = str;

	while ( *d != '\0')
	{
		if ((int)*d == c)
		{
			return (char*)d;
		}
		d++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *d = str;
	char *last = NULL;

	while ( *d != '\0')
	{
		if ((int)*d == c)
		{
			last =(char*)d;
		}
		d++;
	}

	return last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	const char *hay = haystack;
	const char * ndl = needle;
	char *begin = NULL;

	while (*hay != '\0')
	{
		if (*hay == *ndl)
		{
			if (begin == NULL)
			{
				begin = (char*)hay;
			}

			ndl++;
		} else {
			if (*ndl == '\0')
			{
				return begin;
			} else {
				// reset ndl to be found
				ndl = needle;

				begin = NULL;
			}
		}
		hay++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *hay = haystack + strlen(haystack) - 1;
	const char * ndl = needle + strlen(needle) - 1;
	char *begin = NULL;

	while (strlen(hay) != strlen(haystack))
	{
		if (*hay == *ndl)
		{
			begin = (char*)hay;
			ndl--;
		} else {
			if (strlen(ndl + 1) == strlen(needle))
			{
				return begin;
			} else {
				// reset ndl to be found
				ndl = needle + strlen(needle) - 1;

				begin = NULL;
			}
		}

		hay--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	size_t i;
	char *dst = (char*)destination;
	char *src = (char*)source;

	for (i = 0; i < num; i++)
	{
		*(dst + i) = *(src + i);
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dst = (char*)destination;
	const char *src = (const char*)source;

	if (destination >= source && destination <= (source + (int)num))
	{
		size_t i;
		for (i = num; i > 0; i--)
		{
			*(dst + i - 1) = *(src + i - 1);
		}
	} else {
		size_t i;
		for (i = 0; i < num; i++)
		{
			*(dst + i) = *(src + i);
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	if (num == 0)
	{
		return 0;
	}

	unsigned char *p1 = (unsigned char*) ptr1;
	unsigned char *p2 = (unsigned char*) ptr2;

	size_t i;
	int s;
	for (i = 0; i < num; i++)
	{
		s = *p1 - *p2;
		if (s != 0)
		{
			break;
		}
	}

	return s;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	size_t i;
	char *src = (char*)source;

	for (i = 0; i < num; i++)
	{
		*(src + i) = (char) value;
	}

	return source;
}
