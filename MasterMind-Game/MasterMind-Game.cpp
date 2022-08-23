#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void oneStep()
{
    printf(" +++++MASTERMIND GAME+++++\n");
    printf("The computer will randomly select 4 out of 8 numbers.\n");
}

void start(int a, int b, int c, int d)
{
    printf("start game\n");
    printf("%d %d %d %d\n", a, b, c, d);
    int konum = 0;
    int sayy = 0;
    int x[4];
    while (1)
    {
        printf(" Please enter 4 digit numbers one by one\n");
        for (int i = 0; i != 4; ++i) {
            scanf_s("%d", &x[i]);
        }
        for (int i = 0; i != 4; i++) {
            if (a == x[i] || b == x[i] || c == x[i] || d == x[i]) {
                sayy++;
                konum++;
            }
        }
        printf("\n\n You have %d true positions\n\n You have %d true numbers",
            konum, sayy);
        sayy = 0;
        konum = 0;
        if (a == x[0] && b == x[1] && c == x[2] && d == x[3])
        {
            printf("\n\nThanks you win");
            break;
        }
    }
}
int main()
{
    oneStep();
    unsigned int numbers[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    srand(time(NULL));
    int a, b, c, d;
    int array[4];
    int next = 0;
    int index = 0;
    while (1)
    {
        index = rand() % 7 + 1;

        if (numbers[index] != 0)
        {
            array[next] = numbers[index];
            numbers[index] = 0;
            next++;
        }

        if (next == 4)
        {
            break;
        }
    }
    start(array[0], array[1], array[2], array[3]);
    return 0;
}
