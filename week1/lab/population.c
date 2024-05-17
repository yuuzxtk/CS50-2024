#include <stdio.h>
#include <cs50.h>
#include <math.h>
/*int n = 0;
int f = 0;
int population(void);
int final(void);
int population(void){
    do{
        n = get_int("digite a população inicial de burros: ");
    } while (n < 9);
    return n;
}
int final(void){
    do{
        f = get_int("Digite a população final requerida: ");
    } while(f < n);
    return f;
} */

int main (void)
{
    int years = 0;
    int n = 0;
    int f = 0;
        do{
        n = get_int("digite a população inicial de burros: ");
    } while (n < 9);
        do{
        f = get_int("Digite a população final requerida: ");
    } while(f < n);
    if(n != f){
        do{
             n += n/3 - n/4;
            years++;
            /* p += p/3  é o mesmo que population = population + p/3 */
        } while(f > n);
        printf("Years: %i", years);

    } else
    {
        printf("no years required.");
    }

}

