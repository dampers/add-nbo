#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(int ac, char *av[])
{

	if(ac != 3)
	{
		printf("Usage :/%s <file1> <file2>\n", av[0]);
		exit(1);
	}	

	FILE *fpa, *fpb;
	uint32_t a = 0, b = 0;
	char buf[5];

	fpa = fopen(av[1], "rb");
	if(fpa == NULL)
	{
		printf("file %s open error\n", av[1]);
		exit(2);
	}
	fpb = fopen(av[2], "rb");
	if(fpb == NULL)
	{
		printf("file %s open error\n", av[2]);
		exit(2);
	}

	fread(buf, 1, 4, fpa);
	uint32_t* pa = reinterpret_cast<uint32_t*>(buf);
	a = *pa;
	a = ntohl(a);
	
	fread(buf, 1, 4, fpb);
	uint32_t* pb = reinterpret_cast<uint32_t*>(buf);
	b = *pb;
	b = ntohl(b);
	
	fclose(fpb);
	fclose(fpa);
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);

	return 0;
}
