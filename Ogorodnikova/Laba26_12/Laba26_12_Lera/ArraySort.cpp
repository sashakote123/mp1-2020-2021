#include <cstdlib>
#include <stdio.h>
#include "ArraySort.h"
#include "If_and_swap.h"

void insert_sort(float* arr, int n)
{
    int j = 0;
	float t = 0;
    for (int i = 1; i < n; ++i)
    {
        t = arr[i];
        for (j = i; j > 0; --j)
        {
            if (arr[j - 1] > t)
            {
                arr[j] = arr[j - 1];
                _if++;
                _swap++;
            }
            else
            {
                _if++;
                break;
            }
        }
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
                {
                    arr[j] = arr[j - step];
                    _if++;
                    _swap++;
                }
                else
                {
                    _if++;
                    break;
                }
            }
            arr[j] = t;
        }
    }
}

void merge(float* arr, float* left, float* right, int l, int r)
{
    int i = 0, j = 0, k = 0;
    while ((i < l) && (j < r))
    {
        _if++;
        _swap++;
        if (left[i] < right[j])
        {
            
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < l)
    {
        _swap++;
        arr[k++] = left[i++];
    }
    while (j < r)
    {
        _swap++;
        arr[k++] = right[j++];
    }
}

void merge_sort(float* array, int n)
{
    int pivot = n / 2;
    if (n < 2)
    {
        _if++;
    }
    else
    {
        float* left = (float*)malloc(pivot * sizeof(float));
        float* right = (float*)malloc((n - pivot) * sizeof(float));
        for (int i = 0; i < pivot; i++)
        {
            left[i] = array[i];
        }
        for (int i = pivot; i < n; i++)
        {
            right[i - pivot] = array[i];
        }
        merge_sort(left, pivot);
        merge_sort(right, n - pivot);
        merge(array, left, right, pivot, n - pivot);
        free(left);
        free(right);
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
            _if++;
            ++i;
        }

        while (arr[j] > pivot)
        {
            _if++;
            --j;
        }

        if (i <= j)
        {
            if (i < j)
            {
                _if++;
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
        _if++;
       hoar_sort(arr, i, n);
    }
    if (j > first)
    {
        _if++;
        hoar_sort(arr, first, j);
    }
}

void print_if_and_swap()
{
    printf("%d,  %d \n", _if, _swap);
}
void obnull_if_swap()
{
    _if = 0;
    _swap = 0;
}