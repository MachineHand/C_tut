#include <stdio.h>
int scan();
int mission(int *ptr);
int num1[10];

int main(void)
{
	scan();
	printf("press number : ");
	mission(num1);
	return 0;
}
int scan()
{
	for (int i = 0; i < 10; i++)
	{
		printf("number %d : ", i + 1);
		scanf_s("%d", &num1[i]);
	}
}

int mission(int* ptr)
{
	for (int j = 0; j <10; j++) {
		for (int i = 0; i < 9; i++)
		{
			if (ptr[i] > ptr[i + 1])
			{
				int temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ptr[i]);
	}

}