// SPDX-License-Identifier: BSD-3-Clause

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define CAT_FILE    "my_file"

int main(void)
{
	int fd;
	int r;

    // open the file
	fd = open(CAT_FILE, O_CREAT, S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
	if (fd < 0)
		exit(EXIT_FAILURE);

    // read data into the buffer
    char buffer[250];
    r = read(fd, buffer, 250);
    while (r != 0)
    {
        // write data in stdout
        write(1, buffer, r);
        r = read(fd, buffer, 250);
    }

    r = close(fd);
	if (r < 0)
		exit(EXIT_FAILURE);

	return 0;
}
