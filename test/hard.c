#include <stdio.h>
#include <time.h>

#define MAX_COUNT  15
#define MAX_MIXING_COUNT 30 //섞는 횟수

void shuffle(int puzzle[4][4]); // 중복없이 배열 섞기
void print(int puzzle[4][4]); // 배열 출력

int main(void)
{
	int puzzle[4][4];
	shuffle(puzzle[4][4]);
	print(puzzle[4][4]);

	return 0; // main만
}

void shuffle(int puzzle[4][4])
{
	srand(time(NULL));
	int data[MAX_COUNT]; // 1~15 까지 중복없이 섞은 배열
	int x, y,temp; // 섞기위한 변수
	int count = 0; // data[]에 사용한 count.

	for (int i = 0; i < MAX_COUNT; i++)
	{
		data[i] = i + 1;
	}

	for (int i = 0; i < MAX_MIXING_COUNT; i++)
	{
		x = rand() % MAX_COUNT;
		y = rand() % MAX_COUNT;

		if (x != y) //동일한 위치가 선택된 경우에는 무시한다.
		{
			//선택된 두값을 서로 바꾼다.
			temp = data[x];
			data[x] = data[y];
			data[y] = temp;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
				puzzle[i][j] = 0;
			else
				puzzle[i][j] = data[count++]; //1~15
		}
	}
}

void print(int puzzle[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			if (puzzle[i][j] == 0)
				printf("     ");
			else
			{
				printf(" %d  ", puzzle[i][j]);
				if (puzzle[i][j] <= 10)  //깔끔하게 정리 
					printf(" ");
			}
		}
		printf("\n");
	}
}