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
	FILE *ifp, *bfp;
	FileData myData;

	if ((ifp = fopen(argv[1], "r")) == NULL)
	{       
		printf("Error opening file!\n");
		return;
	} 

	if ((bfp = fopen(argv[2], "wb")) == NULL)
	{
		printf("Error opening file!\n");
		return;
	}
	while(fscanf(ifp, "%d %lf %[^\n]s", &myData.a, &myData.b, &myData.dataStr)==3)
	{
		fwrite(&myData, sizeof(FileData), 1, bfp);
	}

	fclose(ifp);
	fclose(bfp);
}


