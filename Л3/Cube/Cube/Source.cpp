#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CreateArray(short unsigned**** cube, short unsigned N);
void InitilizeCube(short unsigned**** cube, short unsigned N);
void CheckOne(short unsigned**** cube, short unsigned N);
void FreeArray(short unsigned**** cube, short unsigned N);

int main(void)
{
    short unsigned*** cube, N;

    printf("Enter the cube size: ");
    while (!scanf_s("%hu", &N)) {
        printf_s("Invalid input. Try again.\nN = ");
        getchar();
    }

    if (CreateArray(&cube, N))
        return 0;

    printf_s("Clearance coordinates:\n");
    InitilizeCube(&cube, N);

    FreeArray(&cube, N);
    return 0;
}

int CreateArray(short unsigned**** cube, short unsigned N)
{
    if (!(*cube = (short unsigned***)malloc(N * (sizeof(short unsigned**))))) {
        printf("Problem with memory allocation.");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        (*cube)[i] = (short unsigned**)malloc(N * sizeof(short unsigned*));

        for (int j = 0; j < N; j++)
            (*cube)[i][j] = (short unsigned*)malloc(N * sizeof(short unsigned));
    }
    return 0;
}

void InitilizeCube(short unsigned**** cube, short unsigned N)
{
   srand((unsigned int)(time(NULL))); 
   for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                (*cube)[i][j][k] = rand() % 2;
    
    CheckOne(cube, N);
    
}

void CheckOne(short unsigned**** cube, short unsigned N)
{
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if ((*cube)[i][j][k] == 0)
                    printf_s("i = %d, j = %d, k = %d\n", i, j, k);
}

void FreeArray(short unsigned**** cube, short unsigned N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            free((*cube)[i][j]);

    for (int k = 0; k < N; k++)
        free((*cube)[k]);

    free((*cube));
}