#define MAX 2147483646
#define MAX_F 3.402823466e+35F
#define EPS 1e-12

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void russianunits(double length);
void englishunits(double length);
void siunit(double length);
void info();
float verification_f();
int verification_i(int n);

int main(void)
{
    int a, res;
    double length;
    for (;;)
    {
        printf("\n1.Enter the data \n2.Exit\n");
        a = verification_i(2);
        system("cls");
        switch (a)
        {
        case 1:
            printf("\nEnter the length in metres\n");
            length = verification_f();
            break;
        case 2:
            return 0;
        }
        system("cls");
        for (;;)
        {
            printf("\nChoose what you want:\n1.Convert length to traditional Russian units \n2.Convert length to traditional English units");
            printf("\n3.Report output in Units Si \n4.Information about versionand author \n5.Exit to menu1\n ");
            a = verification_i(5);
            system("cls");
            switch (a)
            {
            case 1:
                russianunits(length);
                break;
            case 2:
                englishunits(length);
                break;
            case 3:
                siunit(length);
                break;
            case 4:
                info();
                break;
            case 5:
                break;
            }
            if (a == 5)
            {
                break;
            }
            printf("\nDo you want to continue?\n1.Yes \n2.No\n");
            a = verification_i(2);
            if (a == 2)
            {
                return 0;
            }
        }
    }
    return 0;
}

void russianunits(double length)
{
    system("cls");
    length /= 0.0445;
    printf("\nYour length is %.2le tops", length);
    length /= 16;
    printf("\nYour length is %.2le arshin", length);
    length /= 3;
    printf("\nYour length is %.2le fathom", length);
    length /= 500;
    printf("\nYour length is %.2le verst\n", length);
}

void englishunits(double length)
{
    system("cls");
    length /= 0.0254;
    printf("\nYour length is %.2le inchs", length);
    length /= 12;
    printf("\nYour length is %.2le foots", length);
    length /= 3;
    printf("\nYour length is %.2le yards", length);
    length /= 1760;
    printf("\nYour length is %.2le miles\n", length);
}

void siunit(double length)
{
    system("cls");
    length *= 1000;
    printf("\nYour length is %.2le millimeters", length);
    length /= 10;
    printf("\nYour length is %.2le centimeters", length);
    length /= 100;
    printf("\nYour length is %.2le meters", length);
    length /= 1000;
    printf("\nYour length is %.2le kilometers\n", length);
}

void info()
{
    system("cls");
    printf("\nVersion of program: 1.0 \nAuthor of program: student of group 953503 Zakharova Anna\n");
}

float verification_f()
{
    float f;
    char term;
    while (1)
    {
        rewind(stdin);
        if (scanf_s("%f%c", &f, &term) != 2 || term != '\n' || (f > MAX_F && f < -MAX_F) || f < 0 || (f > -EPS && f < EPS))
        {
            printf("Incorrect entry. \n");
        }
        else
        {
            break;
        }
    }
    return f;
}

int verification_i(int n)
{
    int choice = 0;
    char term1;
    while (1)
    {
        rewind(stdin);
        if (scanf_s("%d%c", &choice, &term1) != 2 || term1 != '\n' || choice <= 0 || choice > n)
        {
            printf("Incorrect entry.\n");
        }
        else
        {
            return choice;
        }
    }
}