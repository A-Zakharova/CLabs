#pragma once
#include "Node.h"
typedef struct tree
{
	Node* root;
} Tree;

void AddNode(Node** tmp, int num);
void PrintTreeInAscendingOrder(Node* tmp);
void PrintTreeInDescendingOrder(Node* tmp);
int CalculateSum(Node* tmp);