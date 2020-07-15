#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t nbo(char* file)
{
	FILE *fp;
	fp = fopen(file, "rb");
	if(fp == NULL)
	{
		printf("file %s open error", file);
		exit(2);
	}
	char buf[5];
	fread(buf, 1, 4, fp);
	uint32_t* p = reinterpret_cast<uint32_t*>(buf);
	fclose(fp);
	return ntohl(*p);
}

int main(int ac, char *av[])
{

	if(ac != 3)
	{
		printf("Usage :/%s <file1> <file2>\n", av[0]);
		exit(1);
	}

	uint32_t a = nbo(av[1]), b = nbo(av[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);

	return 0;
}
