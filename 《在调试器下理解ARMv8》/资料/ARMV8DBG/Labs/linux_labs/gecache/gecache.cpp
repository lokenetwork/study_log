// gecache.cpp: 定义应用程序的入口点。
//
#include <stdio.h>
#include <stdlib.h>
#include "gecache.h"
#include "clabs.h"

#define GE_CACHE_VER 6

int main(int argc, char* argv[])
{
	int labno = 2;
	int loops = 1000;
	int ret = 0;
	printf("GeCache [labno] [loops] rev%d by Raymond.\n", GE_CACHE_VER);

	if (argc > 1)
		labno = atoi(argv[1]);
	if (argc > 2)
		loops = atoi(argv[2]);

	switch (labno)
	{
	case 1:
		ret = GeLabIntactInterlace(loops);
		break;
	case 2:
		ret = GeLabIntactBatch(loops);
		break;
	case 3:
		ret = GeLabIntactBatchUnlikely(loops);
		break;
	default:
		printf("bad lab no\n");
		break;
	}
	printf("done with ret = %d\n", ret);

	return 0;
}
