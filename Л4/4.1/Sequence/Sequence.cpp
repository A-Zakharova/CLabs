#include <iostream>
#include <string>


int main()
{
    char line[] = "abdabdabdabdabd";
    char subsequence[] = "abd";

    char* pL = line;
    char* pS = subsequence;

    int flagOk = 0;
    int counter = 0;

    while (*pL != 0) {
        while ((*pS != 0)) {
            if (*pL == *pS) {
                flagOk = 1;
                pS++;
            }
            else {
                flagOk = 0;
                break;

            }
            pL++;
        }
        if (flagOk) {
            counter++;
            pS = subsequence;
        }
        else {
            break;
        }
    }

    if ((counter > 1) && (flagOk))
        printf("Your line is periodic sequence");
    else
        printf("Your line is not periodic sequence");

}