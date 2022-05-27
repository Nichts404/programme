#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintArr(int*a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void CountSort(int*a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	//统计次数，统计映射相对位置出现的次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(count);
}

CountSortTest()
{
	int a[] = { 3, 7, 8, 6, 5, 1, 2, 9, 0, 4 };
	int size = sizeof a / sizeof(int);
	CountSort(a, size);
	PrintArr(a, size);
}

int main()
{
	CountSortTest();
	return 0;
}