#include <stdio.h>
#include <malloc.h> 
#include <string.h> 

typedef struct item {
	int digit;
	struct item* next;
	struct item* prev;
} Item;

typedef struct mnumber {
	Item* head;
	Item* tail;
	int n;
} MDNumber;

MDNumber CreateMNumberFromString(char* initStr);
MDNumber CreateMNumberFromInt(int initNum);
void AddDigitToHead(MDNumber* number, int digit);
void AddDigitToTail(MDNumber* number, int digit);
void PrintMNumber(MDNumber number);
int Equal(MDNumber number1, MDNumber number2);
MDNumber SumMNumber(MDNumber number1, MDNumber number2);
void FreeMNumber(MDNumber* number);
MDNumber LongMulShort(MDNumber number1, int intNumber);
MDNumber LongDivShort(MDNumber number1, int intNumber);
MDNumber LongModShort(MDNumber number1, int intNumber);
MDNumber SubtractMNumber(MDNumber number1, MDNumber number2);
MDNumber CloneMNumber(MDNumber number);
void DeleteTailDigit(MDNumber* number);

int main()
{
	MDNumber mn1 = CreateMNumberFromString("6732847647328");
	MDNumber mn2 = CreateMNumberFromString("6732847647328");
	MDNumber mn3 = CreateMNumberFromString("111111111111119");
	MDNumber mn4 = CreateMNumberFromString("78901");
	MDNumber tmp;
	printf("mn1: ");
	PrintMNumber(mn1);
	printf("\n");
	printf("mn2: ");
	PrintMNumber(mn2);
	printf("\n");
	printf("mn3: ");
	PrintMNumber(mn3);
	printf("\n");
	printf("Equal(mn1,mn2) : %d\n", Equal(mn1, mn2));
	printf("Equal(mn2,mn3) : %d\n", Equal(mn2, mn3));
	printf("Equal(mn3,mn2) : %d\n", Equal(mn3, mn2));

	printf("mn4: ");
	PrintMNumber(mn4);
	printf("\n");

	printf("LongMulShort(mn4, 11) : ");
	tmp = LongMulShort(mn4, 11);
	PrintMNumber(tmp);
	printf("\n");
	FreeMNumber(&tmp);

	printf("LongModShort(mn4, 10) : ");
	tmp = LongModShort(mn4, 10);
	PrintMNumber(tmp);
	printf("\n");
	FreeMNumber(&tmp);

	printf("LongDivShort(mn4, 10) : ");
	tmp = LongDivShort(mn4, 10);
	PrintMNumber(tmp);
	printf("\n");
	FreeMNumber(&tmp);
}

MDNumber CreateMNumberFromString(char* initStr)
{
	MDNumber number = { NULL, NULL, 0 };
	int n;
	for (n = strlen(initStr) - 1; n >= 0; n--)
		AddDigitToHead(&number, initStr[n] - '0');
	return number;
}

MDNumber CreateMNumberFromInt(int initNum)
{
	MDNumber number = { NULL, NULL, 0 };
	if (initNum == 0)
	{
		AddDigitToHead(&number, 0);
		return number;
	}
	while (initNum)
	{
		AddDigitToHead(&number, initNum % 10);
		initNum /= 10;
	}
	return number;
}

void AddDigitToTail(MDNumber* number, int digit)
{
	Item* p = (Item*)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else {
		number->tail->prev = p;
		p->next = number->tail;
		number->tail = p;
	}
	number->n++;
}

void AddDigitToHead(MDNumber* number, int digit)
{
	Item* p = (Item*)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else {
		number->head->next = p;
		p->prev = number->head;
		number->head = p;
	}
	number->n++;
}

void PrintMNumber(MDNumber number)
{
	Item* p = number.head;
	while (p) {
		printf("%d", p->digit);
		p = p->prev;
	}
}

int Equal(MDNumber number1, MDNumber number2)
{
	if (number1.n > number2.n) return 1;
	if (number2.n > number1.n) return -1;

	Item* p1 = number1.head;
	Item* p2 = number2.head;
	while (p1)
	{
		if (p1->digit > p2->digit) return 1;
		if (p2->digit > p1->digit) return -1;
		p1 = p1->prev;
		p2 = p2->prev;
	}
	return 0;
}

MDNumber LongDivShort(MDNumber number1, int intNumber)
{
	MDNumber clone = CloneMNumber(number1);
	MDNumber divider = CreateMNumberFromInt(intNumber);
	MDNumber subtrahend = CloneMNumber(divider);
	MDNumber res = { NULL,NULL, 0 };
	int digit = 0, save = 0;
	MDNumber toFree;

	while (subtrahend.n < clone.n)
	{
		AddDigitToTail(&subtrahend, 0);
	}
	while (Equal(clone, divider) >= 0)
	{
		if (Equal(clone, subtrahend) < 0)
		{
			DeleteTailDigit(&subtrahend);
		}
		if (Equal(clone, subtrahend) < 0)
		{
			DeleteTailDigit(&subtrahend);
			AddDigitToTail(&res, 0);
		}
		digit = 0;
		save = subtrahend.n - divider.n;
		while (Equal(clone, subtrahend) >= 0)
		{
			toFree = clone;
			clone = SubtractMNumber(clone, subtrahend);
			FreeMNumber(&toFree);
			digit++;
		}
		AddDigitToTail(&res, digit);
	}
	while (save)
	{
		AddDigitToTail(&res, 0);
		save--;
	}
	if (res.n == 0) AddDigitToHead(&res, 0);
	FreeMNumber(&clone);
	return res;
}

MDNumber LongModShort(MDNumber number1, int intNumber)
{
	MDNumber clone = CloneMNumber(number1);
	MDNumber divider = CreateMNumberFromInt(intNumber);
	MDNumber subtrahend = CloneMNumber(divider);
	MDNumber res = { NULL,NULL, 0 };
	int digit = 0, save = 0;
	MDNumber toFree;

	while (subtrahend.n < clone.n)
	{
		AddDigitToTail(&subtrahend, 0);
	}
	while (Equal(clone, divider) >= 0)
	{
		if (Equal(clone, subtrahend) < 0)
		{
			DeleteTailDigit(&subtrahend);
		}
		if (Equal(clone, subtrahend) < 0)
		{
			DeleteTailDigit(&subtrahend);
			AddDigitToTail(&res, 0);
		}
		digit = 0;
		save = subtrahend.n - divider.n;
		while (Equal(clone, subtrahend) >= 0)
		{
			toFree = clone;
			clone = SubtractMNumber(clone, subtrahend);
			FreeMNumber(&toFree);
			digit++;
		}
		AddDigitToTail(&res, digit);
	}
	while (save)
	{
		AddDigitToTail(&res, 0);
		save--;
	}
	if (res.n == 0) AddDigitToHead(&res, 0);
	FreeMNumber(&res);
	return clone;
}

MDNumber LongMulShort(MDNumber number1, int intNumber)
{
	if (intNumber == 0) return CreateMNumberFromInt(0);
	MDNumber res = { NULL, NULL, 0 };
	MDNumber tmp = { NULL, NULL, 0 };
	MDNumber toFree;
	Item* p1 = number1.tail;
	int sum = 0, pos = 0, counter = 0, zero = 0;

	while (intNumber)
	{
		p1 = number1.tail;
		pos = 0;
		while (p1)
		{
			sum = p1->digit * (intNumber % 10) + pos;
			pos = sum / 10;
			AddDigitToHead(&tmp, sum % 10);
			p1 = p1->next;
		}
		if (pos) AddDigitToHead(&tmp, pos);
		zero = counter;
		while (zero)
		{
			AddDigitToTail(&tmp, 0);
			zero--;
		}
		toFree = res;
		res = SumMNumber(res, tmp);
		FreeMNumber(&toFree);
		FreeMNumber(&tmp);
		intNumber /= 10;
		counter++;
	}
	return res;
}

MDNumber SumMNumber(MDNumber number1, MDNumber number2)
{
	MDNumber sum = { NULL, NULL, 0 };
	Item* p1 = number1.tail;
	Item* p2 = number2.tail;
	int digit1, digit2, pos = 0;
	while (p1 || p2)
	{
		digit1 = digit2 = 0;
		if (p1)
		{
			digit1 = p1->digit;
			p1 = p1->next;
		}
		if (p2)
		{
			digit2 = p2->digit;
			p2 = p2->next;
		}
		AddDigitToHead(&sum, (digit1 + digit2 + pos) % 10);
		pos = (digit1 + digit2 + pos) / 10;
	}
	if (pos) AddDigitToHead(&sum, pos);
	return sum;
}

void FreeMNumber(MDNumber* number)
{
	Item* p = number->tail;
	Item* toFree;
	while (p)
	{
		toFree = p;
		p = p->next;
		free(toFree);
	}
	number->head = number->tail = NULL;
	number->n = 0;
}

MDNumber SubtractMNumber(MDNumber number1, MDNumber number2)
{
	MDNumber substract = CloneMNumber(number1);
	Item* p1 = substract.tail;
	Item* p2 = number2.tail;
	while (p2)
	{
		if (p1->digit < p2->digit)
		{
			p1->next->digit--;
			p1->digit += 10;
		}
		p1->digit -= p2->digit;
		p1 = p1->next;
		p2 = p2->next;
	}
	Item* toFree;
	while (substract.head->digit == 0 && substract.head != substract.tail)
	{
		toFree = substract.head;
		substract.head = substract.head->prev;
		free(toFree);
		substract.n--;
	}
	substract.head->next = NULL;
	return substract;
}

MDNumber CloneMNumber(MDNumber number)
{
	MDNumber clone = { NULL, NULL, 0 };
	Item* p = number.head;
	while (p)
	{
		AddDigitToTail(&clone, p->digit);
		p = p->prev;
	}
	return clone;
}

void DeleteTailDigit(MDNumber* number)
{
	Item* toFree = number->tail;
	number->tail = toFree->next;
	free(toFree);
	number->tail->prev = NULL;
	number->n--;
}