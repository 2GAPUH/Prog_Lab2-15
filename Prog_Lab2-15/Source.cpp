#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLUMNS 200

//ƒан текстовый файл.»спользу€ очередь, переписать
//содержимое его строк в новый текстовый файл, перенос€ при этом в
//конец каждой строки все вход€щие в нее цифры, сохран€€ исходный
//пор€док следовани€ среди цифр и среди остальных символов строки.


void StackLoop()
{
	int userChoice = 0;
	int tmp = 0;
	bool loop = true;
	queue array = {NULL, NULL};

	printf_s("1 - Add new element \n2 - Get with removing \n3 - Get without removing \n4 - Clear \n5 - Task \n0 - Exit \n");

	while (loop)
	{
		printf_s("Your choice: ");
		scanf_s("%d", &userChoice);

		switch (userChoice)
		{
		case 1:
			printf_s("Enter your element: ");
			scanf_s("%d", &tmp);
			PushQueue(&array, tmp);
			break;

		case 2:
			if ((tmp = PopQueue(&array)) != INT_MAX)
				printf_s("Your element: %d\n", tmp);
			else
				printf_s("Your queue is empty.\n");
			break;

		case 3:
			if ((tmp = PeekQueue(&array)) != INT_MAX)
				printf_s("Your element: %d\n", tmp);
			else
				printf_s("Your stack is empty.\n");
			break;

		case 4:
			ClearQueue(&array);
			break;

		case 5:
			FILE* input;
			FILE* output;
			fopen_s(&input, "file.txt", "r");
			fopen_s(&output, "file1.txt", "w");

			while(!feof(input))
			{
				char tmp1 = 0;
				int num = 0;
				fscanf_s(input, "%c", &tmp1);
				if (tmp1 >= '0' && tmp1 <= '9')
				{
					while (tmp1 >= '0' && tmp1 <= '9')
					{
						num = num * 10 + tmp1 - '0';
						fscanf_s(input, "%c", &tmp1);
					}
					PushQueue(&array, num);
				}
				else
				{
					if (tmp1 == '\n' || tmp1 == '\0')
					{
						while (!IsEmptyQueue(&array))
						{
							fprintf_s(output, " %d", PopQueue(&array));
						}
					}
					fprintf_s(output, "%c", tmp1);
				}
						
			}

			fclose(input);
			fclose(output);
			break;
		
		case 0:
			loop = 0;
			break;

		default:

			break;
		}

		PrintQueue(&array);
	}

	ClearQueue(&array);
}


int main()
{
	StackLoop();

	return 0;
}