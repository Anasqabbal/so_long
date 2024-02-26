#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void f(void)
{
	system("leaks a.out");
}

int main()
{
	//atexit(f);
	// char *rs = malloc((BUFFER_SIZE + 1) * sizeof(char));
	int fd = open("a.txt", O_RDONLY);
	int fp = open("b.txt", O_RDONLY);
	// my_memcpy(rs, "hello", BUFFER_SIZE);
	char *res;
	char *str;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fp));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fp));
	printf("%s", get_next_line(fd));
	/*while((res = get_next_line(fd)) && (str = get_next_line(fp)))
	{
		printf("%s", res);
		printf("%s", str);
		free(res);
		free(str);
	}*/
}