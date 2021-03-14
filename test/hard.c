#include <stdio.h>
#include <time.h>

#define MAX_COUNT  15
#define MAX_MIXING_COUNT 30 //섞는 횟수
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int puzzle[4][4];
void shuffle(); // 중복없이 배열 섞기
void print(); // 배열 출력
int move(); // 빈칸이동

int main(void)
{
	shuffle();
	print();
	move();
	return 0; // main만
}

void shuffle()
{
	srand(time(NULL));
	int data[MAX_COUNT]; // 1~15 까지 중복없이 섞은 배열
	int x, y, temp; // 섞기위한 변수
	int count = 0; // data[]에 사용한 count.

	for (int i = 0; i < MAX_COUNT; i++)
	{
		data[i] = i + 1; // 1~15
	}

	for (int i = 0; i < MAX_MIXING_COUNT; i++)
	{
		x = rand() % MAX_COUNT; //if 3 
		y = rand() % MAX_COUNT; //if 5 

		if (x != y) //동일한 위치가 선택된 경우에는 무시한다.
		{
			//선택된 두값을 서로 바꾼다. swap
			temp = data[x];
			data[x] = data[y]; //data[3]값에 data[5]값이 들어간다. -> data[3] = 5
			data[y] = temp;    //									  data[5] = 3
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

void print()
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

int move()
{
	while (1)
	{
		char c;
		int i, j, a, temp1 = 0;
		printf("\n");
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				switch (c)//right
				{
				case RIGHT:
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (puzzle[i][j] == 0)
							{
								temp1 = puzzle[i][j];
								puzzle[i][j] = puzzle[i][j + 1]; //현재 j값은 1
								puzzle[i][j + 1] = temp1;
								system("cls");
								print();
								break;
							}
						}
					}
					break;
				case DOWN:
					for (int i = 3; i >= 0; i--)
					{
						for (int j = 3; j >= 0; j--)
						{
							if (puzzle[i][j] == 0)
							{
								temp1 = puzzle[i][j];
								puzzle[i][j] = puzzle[i + 1][j];
								puzzle[i + 1][j] = temp1;
								system("cls");
								print();
								break;
							}
						}
					}
					break;
				case UP:
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (puzzle[i][j] == 0)
							{
								temp1 = puzzle[i][j];
								puzzle[i][j] = puzzle[i - 1][j];
								puzzle[i - 1][j] = temp1;
								system("cls");
								print();
								break;
							}
						}
					}
					break;
				case LEFT:
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (puzzle[i][j] == 0)
							{
								temp1 = puzzle[i][j];
								puzzle[i][j] = puzzle[i][j - 1];
								puzzle[i][j - 1] = temp1;
								system("cls");
								print();
								break;
							}
						}
					}
				}
			}
			else
				break;
		}
	}