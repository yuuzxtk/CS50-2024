#include <stdio.h>
#include <cs50.h>
#include <math.h>

int b;
int main (void)
{
    do
    {
        b = get_int("Qual a altura da escada de blocos?");
    }
    while(b <= 0 || b > 8);

    for(int x = 0; x <= b - 1; x++)
{
    for(int y = 1; y<= b; y++){

    if(y < b - x)
    printf(" ");
    else
    printf("#");
    }

    printf("\n");
}
}
