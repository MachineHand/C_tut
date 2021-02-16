#include <stdio.h>
#include <time.h>

int puzzle[4][4];
void initAnimalArray();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);

int main(void)
{
	srand(time(NULL));
	initAnimalArray();

	shuffleAnimal();
	

		return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			puzzle[i][j] = -1;
		}
	}
}

void shuffleAnimal()
{
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			printf("%d ",puzzle[x][y]);
		}
		printf("\n");
	}
}

int getEmptyPosition()
{
	// ㅁㅁㅁㅁㅁ 0  1  2  3  4 -> 0 0 0 0 0
	// ㅁㅁㅁㅁㅁ 5  6  7  8  9 -> 1 1 1 1 1
	// ㅁㅁㅁㅁㅁ 10 11 12 13 14 ->2 2 2 2 2
	// ㅁㅁㅁㅁㅁ 15 16 17 18 19 ->3 3 3 3 3


	while (1)
	{
		int randPos = rand() % 16; // 0~19
		// 15->(3,3)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (puzzle[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	// 19-> (3,4)
	return x / 4;
}

int conv_pos_y(int y)
{
	// 19-> 19/5? 몫은 3 나머지 4
	return y % 4; //y를 5로 나눈 나머지 값
}

