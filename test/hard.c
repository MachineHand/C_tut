#include <stdio.h>
#include <time.h>

int puzzle[4][4];

int main(void)
{
	srand(time(NULL));
	int i, j, k, temp;
	int count = 1;
	int ranx = rand() % 4;
	int rany = rand() % 4;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			puzzle[i][j] = count++;
		}
	}

	for (k = 0; k < 4; k++)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[ranx][rany];
				puzzle[ranx][rany] = temp;
			}
		}
	}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				printf("%d ", puzzle[i][j]);
			}
			printf("\n");
		}
		return 0;
}

