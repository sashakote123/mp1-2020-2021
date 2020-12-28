#include <cstdlib>
#include <stdio.h>
#include "ArrayF.h"
void size_arr(float** arr, int* n)
{
	printf("Введите размер массива: ");
	scanf("%d", n);
	free(*arr);
	*arr = (float*)malloc(*n * sizeof(float));
	printf("Готово \n");
	system("pause");
}

void print_arr(float* arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
	system("pause");
}

void keyboard_in(float* arr, int n)
{
	printf("Введите %d элементов в массиве(через пробел): ", n);
	for(int i = 0; i < n; i++)
	{
		scanf("%f", &arr[i]);
	}
}

void arr_rand(float* arr, int n)
{
	int max = 100, min = -100;
	for(int i = 0; i < n; i++)
	{
		arr[i] = (float)(rand()) / RAND_MAX * (max - min) + min;
	}
	printf("Готово\n");
	system("pause");
}