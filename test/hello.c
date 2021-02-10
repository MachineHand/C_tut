#include <stdio.h>
#include <time.h>
// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5]; //카드 지도(20장의 카드)
int checkAnimal[4][5];
char * strAnimal[10];


void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printfAnimals();
void printfQuestion();
int foundAllAnimals();

int main_m_array_project(void)
{
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0; // 실패 횟수

	while (1)
	{
		int select1 = 0; //사용자가 선택한 처음 수
		int select2 = 0; //사용자가 선택한 두번째 수

		printfAnimals(); // 동물 위치 출력
		printfQuestion(); // 문제 출력(카드 지도)
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) //같은 카드 선택시 무효
			continue;

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인

		// 정수 좌표를 (x,y)로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);
		//같은 동물인 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y]==0 //카드가 뒤집히지 않았는지
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			
			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]
			== arrayAnimal[secondSelect_x][secondSelect_y]
			))//두동물이 같은지
		{
			printf("\n\n빙고! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		//다른 동물인 경우
		else
		{
			printf("\n\n 땡!! (틀렸거나, 이미 뒤집힌 카드입니다)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		// 모든 동물을 찾았는지 여부 1:참 0:거짓
		if (foundAllAnimals() == 1)
		{
			printf("\n\n 축하합니다 ! 모든 동물을 다 찾았네요 \n");
			printf("지금까지 총 %d 번 실수하셨습니다.\n", failCount);
			break;
		}

	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";

	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ

	for (int i=0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);


			arrayAnimal[x][y] = i;
		}
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
		int randPos = rand() % 20; // 0~19
		// 19-> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	// 19-> (3,4)
	return x / 5;
}

int conv_pos_y(int y)
{
	// 19-> 19/5? 몫은 3 나머지 4
	return y % 5; //y를 5로 나눈 나머지 값
}

void printfAnimals()// 동물 위치 출력
{
// ㅁㅁㅁㅁㅁ 1  1  2  2  3 
// ㅁㅁㅁㅁㅁ 3  4  4  5  5 
// ㅁㅁㅁㅁㅁ 
// ㅁㅁㅁㅁㅁ 

	printf("\n====이건 비밀인데 .. 몰래 보여주니다====\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n=======================================\n\n");
}

void printfQuestion() // 문제 출력(카드 지도)
{
	printf("\n\n(문제)\n");
	int seq = 0;
					//seq			checkAnimal
// ㅁㅁㅁㅁㅁ 0  1  2  3  4			0 0 0 0 0
// ㅁㅁㅁㅁㅁ하마  6  7  8  9		1 0 0 0 0
// ㅁㅁㅁㅁㅁ 10 11 12 하마 14		0 0 0 1 0
// ㅁㅁㅁㅁㅁ 15 16 17 18 19		0 0 0 0 0

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//카드를 뒤집어서 정답을 맞췃으면 '동물 이름'
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			//아직 뒤집지 못했으면 (정답을 못맞혔으면) 뒷면 -> 위치를 나타내는 숫자
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
				return 0;
		}
	}
	return 1;  //모두 다 찾음
}