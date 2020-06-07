#define MAX_F 3.402823466e+35F
#define EPS 1e-12

# include <stdio.h>
# include <conio.h>
# include <math.h>

float verification_f();

void main(void)
{
    float  number;
    int rubles, coins;
    printf("\nEnter your number: ");
    number = verification_f();
    rubles = (int)number;
    coins = round((number - rubles) *100);
    if (coins == 100)
    {
        rubles++;
        coins = 0;
    }
    printf("\n%d rub. %d cop.", rubles, coins);
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