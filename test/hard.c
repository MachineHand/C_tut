#include <stdio.h>
#include <time.h>

int puzzle[4][4];
int* ppuzle=puzzle;
int i, j, ranx, rany;
int x,y,z = 0;

int main(void)
{
	srand(time(NULL));
	suffle();

	return 0;
}

int suffle()
{
	int count = 1;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			puzzle[i][j] = count++;
		}
	}
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				printf(" %d  ", puzzle[i][j]);
				if (puzzle[i][j] <= 10)  //깔끔하게 정리
					printf(" ");
			}
			printf("\n");
		}
	}
	ranx, rany = rand() % 4; //0~3
		{
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if(ranx==x,rany==x)
					printf(" %d  ", puzzle[ranx][rany]);
					if (puzzle[i][j] <= 10)  //깔끔하게 정리
						printf(" ");
				}
				printf("\n");
			}
		}
	return 0;
}