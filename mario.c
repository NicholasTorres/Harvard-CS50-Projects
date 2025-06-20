#include <stdio.h>
#include <cs50.h>

int response_check(void);

int main(void)
{
    int response = response_check();

    for(int row = 1; row <= response; row++)
    {
        for (int col = 0; col < response - row; col++)
        {
            printf(" ");
        }

        for (int brick = 0; brick < row; brick++)
        {
            printf("#");
        }

        printf("  ");

        for(int brick = 0; brick < row; brick++)
        {
            printf("#");
        }

        printf("\n");
    }

}

int response_check(void)
{
    int response;
    do
    {
        response = get_int("How many blocks? ");
    }
    while(response < 1 || response > 8);
    return response;
}
