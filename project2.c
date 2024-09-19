/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
	printf("Define the InitialiseStory() function\n");
	paragraph[0] = '\0';
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	printf("Define the PrintCave() function\n");
	printf("%d\n", cave[0][0]);
}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
{
	printf("Define the InitialiseCave() function\n");
	printf("%d %c\n", cave[0][0], layout[0]);
}

// As you work on the other tasks, remove the comments below
//int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
//{
//}

//int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
//{
//}

//int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
//{
//}

//void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
//{
//}

//void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
//{
//}

//int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
//{
//}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};

	InitialiseStory(story);
	InitialiseCave(cave, layout);
	PrintCave(cave);

	return 0;
}