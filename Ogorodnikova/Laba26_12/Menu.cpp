#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Menus.h"
#include "ArrayF.h"
#include "ArraySort.h"
void menu(float** arr, int* n)
{
	char c;
	char men[4][50] = { {"Информация о массиве"}, {"Сортировка"}, {"Печать массива"}, {"Выход"} };
	const int max_op = 4;
	int op = 0;
	printf("Размер массива: %d\n", *n);
	while (true)
	{
		system("cls");
		for (int i = 0; i < max_op; i++)
		{
			if (i == op)
			{
				printf("* ");
			}
			else
				printf("  ");
			printf("%s\n", men[i]);
		}
		c = _getch();

		if (c == 72)
		{
			op = (op - 1 + max_op) % max_op;
		}
		if (c == 80)
		{
			op = (op + 1) % max_op;
		}
		if(c == 13)
		{
			switch (op)
			{
			case 0:
				menu_array(arr, n);
				break;
			case 1:
				menu_sort(*arr, *n);
				break;
			case 2:
				print_arr(*arr, *n);
				break;
			case 3:
				c = 27;
				break;
				default:
					break;
			}
		}
		if (c == 27)
		{
			break;
		}
	}
}
void menu_sort(float* arr, int n)
{
	char c;
	char men[5][50] = { {"Сортировка вставками"}, {"Сортировка Шелла"}, {"Слиянием"}, {"Сортировка Хоара"}, {"Выход"} };
	const int max_op = 5;
	int op = 0;
	printf("Размер массива: %d\n", n);
	while (true)
	{
		system("cls");
		for (int i = 0; i < max_op; i++)
		{
			if (i == op)
			{
				printf("* ");
			}
			else
				printf("  ");
			printf("%s\n", men[i]);
		}
		c = _getch();

		if (c == 72)
		{
			op = (op - 1 + max_op) % max_op;
		}
		if (c == 80)
		{
			op = (op + 1) % max_op;
		}
		if (c == 13)
		{
			switch (op)
			{
			case 0:
				insert_sort(arr, n);
				break;
			case 1:
				shell_sort(arr, n);
				break;
			case 2:
				merge_sort(arr, 0, n-1);
				break;
			case 3:
				hoar_sort(arr, 0, n - 1);
				break;
			case 4:
				c = 27;
				break;
			default:
				break;
			}
		}
		if (c == 27)
		{
			break;
		}
	}
}
void menu_array(float** arr, int* n)
{
	char c;
	char men[4][50] = { {"Изменение размера массива"}, {"Заполнение массива рандомными элементами"}, {"Заполнение массива с клавиатуры"}, {"Выход"} };
	const int max_op = 4;
	int op = 0;
	while (true)
	{
		system("cls");
		for (int i = 0; i < max_op; i++)
		{
			if (i == op)
			{
				printf("* ");
			}
			else
				printf("  ");
			printf("%s\n", men[i]);
		}
		c = _getch();

		if (c == 72)
		{
			op = (op - 1 + max_op) % max_op;
		}
		if (c == 80)
		{
			op = (op + 1) % max_op;
		}
		if (c == 13)
		{
			switch (op)
			{
			case 0:
				size_arr(arr, n);
				break;
			case 1:
				arr_rand(*arr, *n);
				break;
			case 2:
				keyboard_in(*arr, *n);
				break;
			case 3:
				c = 27;
				break;
			default:
				break;
			}
		}
		if (c == 27)
		{
			break;
		}
	}
}