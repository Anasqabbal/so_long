#include "get_next_line.h"
#include <stdio.h>

int main()
{
	// char *rs = malloc((BUFFER_SIZE + 1) * sizeof(char));
	int fd = open("a.txt", O_RDONLY);

	// my_memcpy(rs, "hello", BUFFER_SIZE);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	sleep(30);
}