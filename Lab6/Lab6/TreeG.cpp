#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#define N 3
#define M 5
#define COUNT 100
#define RANGE 100
int main()
{
	Tree** array = (Tree**)malloc(N * sizeof(Tree*));
	int i, j;
	for (i = 0; i < N; i++)
	{
		array[i] = (Tree*)malloc(M * sizeof(Tree));
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			array[i][j].root = NULL;
		}
	}
	srand(time(NULL));
	for (i = 0; i < COUNT; i++) {
		AddNode(&array[rand() % N][rand() % M].root, rand() % RANGE);
	}
	int max = CalculateSum(array[0][0].root);
	int iMax = 0;
	int jMax = 0;
	int tmp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			tmp = CalculateSum(array[i][j].root);
			if (tmp > max)
			{
				max = tmp;
				iMax = i;
				jMax = j;
			}
		}
	}
	printf("All trees:\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			PrintTreeInAscendingOrder(array[i][j].root);
			printf("\n");
		}
	}
	printf("------------------------------\n");
	printf("The biggest tree:\n");
	printf("Tree in the ascending order:\n");
	PrintTreeInAscendingOrder(array[iMax][jMax].root);
	printf("\n Tree in the descending order:\n");
	PrintTreeInDescendingOrder(array[iMax][jMax].root);
}