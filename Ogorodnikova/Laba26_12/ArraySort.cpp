#include <cstdlib>
#include <stdio.h>
#include "ArraySort.h"

void insert_sort(float* arr, int n)
{
    int j = 0;
	float t = 0;
    for (int i = 1; i < n; ++i)
    {
        t = arr[i];
        for (j = i; j > 0; --j)
            if (arr[j - 1] > t)
                arr[j] = arr[j - 1];
            else
                break;
        arr[j] = t;
    }
}

void shell_sort(float* arr, int n)
{
    int j = 0;
    float t;
    for (int step = n / 2; step > 0; step /= 2)
    {
        for (int i = step; i < n; i++)
        {
            t = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (t < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = t;
        }
    }
}

void merge(float* arr, int left, int pivot, int right)
{
    int k = left,
		l = 0, r = 0;
    int n1 = pivot - left + 1,
		n2 = right - pivot;
    float* arr1 = (float*)malloc(n1 * sizeof(float));
    float* arr2 = (float*)malloc(n2 * sizeof(float));
	
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[pivot + 1 + j];
    }

    while (l < n1 && r < n2)
    {
        if (arr1[l] <= arr2[r])
        {
            arr[k] = arr1[l];
            l++;
        }
        else 
        {
            arr[k] = arr2[r];
            r++;
        }
        k++;
    }
    while (l < n1)
    {
        arr[k] = arr1[l];
        l++;
        k++;
    }
    while (r < n2)
    {
        arr[k] = arr2[r];
        r++;
        k++;
    }
    free(arr1);
    free(arr2);
}
void merge_sort(float* arr, int left, int n)
{
    int pivot = 0;
    if (left < n)
    {
        pivot = left + (n - left) / 2;
        merge_sort(arr, pivot + 1, n);
        merge(arr, left, pivot, n);
    }
}

void hoar_sort(float* arr, int first, int n)
{
    int i = first, j = n;
	float c = 0;
    const float pivot = arr[(first + n) / 2];
    do
    {
        while (arr[i] < pivot)
        {
            ++i;
        }

        while (arr[j] > pivot)
        {
            --j;
        }

        if (i <= j)
        {
            if (i < j)
            {
                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
            i++;
            j--;
        }

    } while (i <= j);


    if (i < n)
    {
       hoar_sort(arr, i, n);
    }
    if (j > first)
    {
        hoar_sort(arr, first, j);
    }
}