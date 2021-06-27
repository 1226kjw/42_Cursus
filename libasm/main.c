#include <stdio.h>
#include "libasm.h"
int main()
{
	char buf[100];
	char *a = "hello_world";
	printf("ft_strlen(\"%s\") : %d\n", a, ft_strlen(a));
	ft_read(1, buf, 10);
}
