#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <uchar.h>
#include <string.h>

void random(double* arr, size_t size);
void check(double* arr, size_t size);
void bubble_sort1(double* arr, size_t size);
void bubble_sort2(double* arr, size_t size);
void bubble_sort(double* arr, size_t size);
void comb_sort(double* arr, size_t size);
void output(double* arr, size_t size);
void merge(double* arr, double* scndarr, int scndCount, double* thrarr, int thrCount);
void merge_sort(double* arr, size_t size);
void counter(int cmp, int c);
void comp(int cmp);
void create_counters(double* data, long* counters, long N);
void radix_pass(short Offset, long N, double* source, double* dest, long* count);
void radix_sort(double* in, double* out, long* counters, long N);

int cmp = 0;
int c = 0;
double* arr;
size_t size;
long N;



int main()
{
	int input;
	int input1;
	printf("Which array do you want to create?\n");
	printf("1. Array with elements in ascending order.\n");
	printf("2. The random array.\n");
	printf("3. The inverted array.\n");
	printf("Your choice:");
	scanf_s("%d", &input1);
	printf("What sort do you want to use?\n");
	printf("1. Bubble Sort\n");
	printf("2. Comb Sort\n");
	printf("3. Merge Sort\n");
	printf("4. Radix Sort\n");
	printf("Your choice:");
	scanf_s("%d", &input);


	double* arr;
	int size;
	long* counters = (long*)malloc(1024 * sizeof(double));

	srand(time(0));

	printf("Size = ");
	scanf_s("%d", &size);
	if (size < 1) return 1;

	arr = (double*)malloc(sizeof(double) * size);
	double* arr2 = (double*)malloc(sizeof(double) * size);
	if (arr == 0) return 1;

	switch(input1)
	{
	case 1:
		random(arr, size);
		bubble_sort1(arr, size);
		output(arr, size);
		break;
	case 2:
		random(arr, size);
		output(arr, size);
		break;
	case 3:
		random(arr, size);
		bubble_sort2(arr, size);
		output(arr, size);
		break;
	default:
		printf("\n\nIncorrect input\n\n");
	} 
	switch (input)
	{
	case 1:
		bubble_sort(arr, size);
		output(arr, size);
		counter(cmp, c);	
		break;
	case 2:
		comb_sort(arr, size);
		output(arr, size);
		counter(cmp, c);
		break;
	case 3:
		merge_sort(arr, size);
		output(arr, size);
		comp(cmp);
		break;
	case 4:
		radix_sort(arr, arr2, counters, size);
		output(arr, size);
		counter(cmp, c);
		break;
	default:
		printf("\n\nIncorrect input\n");
	}
	 check(arr, size);


}

void random(double* arr, size_t size)
{
	int i;
	printf("\nArray:\n");
	for (i = 0; i < size; i++)
		arr[i] = rand() % 100;
	printf("%.4lf ", arr[i]);
}
void check(double* arr, size_t size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			printf("\nSort is incorrect\n");
			break;
		}
		else
		{
			printf("\nSort is correct\n");
			break;
		}
	}
}


void output(double* arr, size_t size)
{
	printf("\nArray:\n");
	for (int i = 0; i < size; i++)
		printf("%.4lf ", arr[i]);

}

void counter(int cmp, int c)
{
	printf("\n\nComparisons: %d Permutations: %d\n\n", cmp, c);
}

void comp(int cmp)
{
	printf("\nComparisons: %d\n\n", cmp);
}
void bubble_sort1(double* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				double tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void bubble_sort2(double* arr, size_t size)
{

	for (size_t i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				double tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;

			}
		}
	}
}

void bubble_sort(double* arr, size_t size)
{
	int flag = 1;
	for (size_t i = 0; i < size - 1 && flag; i++)
	{
		flag = 0;
		for (int j = size - 1; j > i; j--)
		{
			cmp++;
			if (arr[j - 1] > arr[j])
			{
				c++;
				double tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				flag = 1;
			}
		}
	}
}



void comb_sort(double* arr, size_t size)
{
	int step = size - 1;
	double factor = 1.2473309;

	while (step >= 1)
	{
		for (int i = 0; i + step < size; i++)
		{
			cmp++;
			if (arr[i] > arr[i + step])
			{
				c++;
				double tmp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = tmp;
			}
		}
		step /= factor;

	}

}

void merge(double* arr, double* scndarr, int scndCount, double* thrarr, int thrCount)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;

	while (i < scndCount && j < thrCount)
	{
		cmp++;
		if (scndarr[i] < thrarr[j])
		{
			arr[k] = scndarr[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = thrarr[j];
			k++;
			j++;
		}
	}
	while (i < scndCount)
	{
		arr[k] = scndarr[i];
		k++;
		i++;
	}
	while (j < thrCount)
	{
		arr[k] = thrarr[j];
		k++;
		j++;
	}

}
void merge_sort(double* arr, size_t size)
{
	int mid, i;
	double* scndarr, * thrarr;
	if (size < 2)
	{
		return;
	}
	mid = size / 2;
	scndarr = (double*)malloc(mid * sizeof(double));
	thrarr = (double*)malloc((size - mid) * sizeof(double));

	for (i = 0; i < mid; i++)
	{
		scndarr[i] = arr[i];
	}
	for (i = mid; i < size; i++)
	{
		thrarr[i - mid] = arr[i];
	}
	merge_sort(scndarr, mid);
	merge_sort(thrarr, size - mid);
	merge(arr, scndarr, mid, thrarr, size - mid);
	free(scndarr);
	free(thrarr);

}

void create_counters(double* data, long* counters, long N)
{

	unsigned char* bp = (unsigned char*)data;

	unsigned char* dataEnd = (unsigned char*)(data + N);
	unsigned short i;
	for (int i = 0; i < 256 * sizeof(double); i++)
		counters[i] = 0;

	while (bp != dataEnd)
	{
		for (i = 0; i < sizeof(double); i++)
			counters[256 * i + *(bp++)]++;
	}

}

void radix_pass(short Offset, long N, double* source, double* dest, long* count)
{
	double* sp;
	long s = 0, d, i, * cp = count;
	unsigned char* bp;

	for (i = 256; i > 0; i--, ++cp)
	{
		d = *cp; *cp = s; s += d;
	}

	bp = (unsigned char*)source + Offset;
	sp = source;
	for (i = N; i > 0; i--, bp += sizeof(double), ++sp)
	{
		cp = count + *bp; dest[*cp] = *sp; (*cp)++;
	}
	c += N;
}

void radix_sort(double* in, double* out, long* counters, long N)
{

	long* count;

	create_counters(in, counters, N);

	for (unsigned short i = 0; i < sizeof(double); i++)
	{
		count = counters + 256 * i;
		radix_pass(i, N, in, out, count);
		for (long j = 0; j < N; j++)
			in[j] = out[j];
	}
}
