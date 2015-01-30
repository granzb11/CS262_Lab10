#include <stdio.h>
#include <stdlib.h>
#define MAXCHARS 55

typedef struct _FileData
{
	int a;
	double b;
	char dataStr[56];
}FileData;

int main(int argc, char **argv)
{
	FILE *bfp, *ifp;
	char line[MAXCHARS];
	FileData myData;

	if((bfp = fopen(argv[1], "rb")) == NULL)
	{
		printf("Error opening file!\n");
		return;
	}

	if((ifp = fopen(argv[2], "w")) == NULL)
	{
		printf("Error opening file!\n");
	}

	while(fread(&myData, sizeof(FileData), 1, bfp))
	{
		fprintf(ifp, "%d\n%.3f\n%s\n", myData.a, myData.b, myData.dataStr);
	printf("\n%s\n", myData.dataStr);
	}

	fclose(ifp);
	fclose(bfp);
}
