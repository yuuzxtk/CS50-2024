#include <cs50.h>
#include <math.h>
#include <stdio.h>
/*
AMEX - 15 digits, starts w/ 34 or 37
MASTERCARD - 16 digits, starts w/ 51, 52, 53, 54 or 55
VISA - 13 or 16 digits, starts w/ 4
int main (void){
*/
int primeiros_digitos(long num_cartao, int numero_digitos);
int num_digitos(long num_cartao);
int validacao_multiplicacao(long num_cartao);
int somar(long num_cartao);
int validar(int resultado, int dois_primeiros_digitos, int numero_digitos);

int main(void)
{
    long num_cartao = get_long("Digite o numero do cartao: ");
    int numero_digitos = num_digitos(num_cartao);
    int dois_primeiros_digitos = primeiros_digitos(num_cartao, numero_digitos);
    int multiplicacao = validacao_multiplicacao(num_cartao);
    int soma = somar(num_cartao);

    int resultado = multiplicacao + soma;

    validar(resultado, dois_primeiros_digitos, numero_digitos);
}

// funções
int num_digitos(long num_cartao)
{
    int num_digitos = 0;
    while (num_cartao > 0)
    {
        num_cartao /= 10;
        num_digitos++;
    }
    return num_digitos;
}

int primeiros_digitos(long num_cartao, int numero_digitos)
{
    int primeiros_digitos =
        num_cartao / pow(10, numero_digitos - 2); // pow(x, ...) = x^numeros_digitos - 2
    return primeiros_digitos;
}

int validacao_multiplicacao(long num_cartao)
{
    int multiplicacao = 0;
    int operacao;
    while (num_cartao > 0)
    {
        num_cartao /= 10;
        operacao = (num_cartao % 10) * 2;
        if (operacao > 9)
        {
            operacao = (operacao % 10) + (operacao / 10);
        }
        multiplicacao = operacao + multiplicacao;
        num_cartao /= 10;
    }
    return multiplicacao;
}

int somar(long num_cartao)
{
    int soma = 0;
    while (num_cartao > 0)
    {
        soma = (num_cartao % 10) +
               soma; // não divide definitiamente, portanto precisamos dividir por 100
        num_cartao /= 100;
    }
    return soma;
}

int validar(int resultado, int dois_primeiros_digitos, int numero_digitos)
{
    if (resultado % 10 == 0)
    {
        if ((dois_primeiros_digitos == 34 || dois_primeiros_digitos == 37) &&
            (numero_digitos == 15))
        {
            return printf("AMEX\n");
        }
        else if ((dois_primeiros_digitos == 51 || dois_primeiros_digitos == 52 ||
                  dois_primeiros_digitos == 53 || dois_primeiros_digitos == 54 ||
                  dois_primeiros_digitos == 55) &&
                 (numero_digitos == 16))
        {
            return printf("MASTERCARD\n");
        }
        else if ((dois_primeiros_digitos >= 40 && dois_primeiros_digitos <= 49) &&
                 (numero_digitos == 16 || numero_digitos == 13))
        {
            return printf("VISA\n");
        }
        else
        {
            return printf("INVALID\n");
        }
    }
    else
    {
        return printf("INVALID\n");
    }
}
