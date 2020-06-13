#include <malloc.h>
#include "Tree.h" 

void AddNode(Node** tmp, int num)
{
	if (*tmp == NULL)
	{
		*tmp = (Node*)malloc(sizeof(Node));
		(*tmp)->pLeft = NULL;
		(*tmp)->pRight = NULL;
		(*tmp)->num = num;
	}
	else if (num > (*tmp)->num)
	{
		AddNode(&(*tmp)->pRight, num);
	}
	else if (num < (*tmp)->num)
	{
		AddNode(&(*tmp)->pLeft, num);
	}
}

void PrintTreeInAscendingOrder(Node* tmp)
{
	if (tmp == NULL)   
	{
		return;
	}
	PrintTreeInAscendingOrder(tmp->pLeft);  
	printf("%d\t", tmp->num);
	PrintTreeInAscendingOrder(tmp->pRight);  
}

void PrintTreeInDescendingOrder(Node* tmp)
{
	if (tmp == NULL)  
	{
		return;
	}
	PrintTreeInDescendingOrder(tmp->pRight);  
	printf("%d\t", tmp->num);
	PrintTreeInDescendingOrder(tmp->pLeft);  
}

int CalculateSum(Node* tmp)
{
	if (tmp == 0)   
	{
		return 0;
	}
	return tmp->num + CalculateSum(tmp->pLeft) + CalculateSum(tmp->pRight);
}
