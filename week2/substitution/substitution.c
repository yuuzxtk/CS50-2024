#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// criptografia com chave de 26 caracteres
// chave PRECISA de 26 caracteres

int main(int argc, string argv[])
{
    if (argc != 2)
    { // só aceita comandos de um periodo
        printf("A chave precisa ter 26 caracteres! \n");
        return 1;
    }
    if (strlen(argv[1]) < 26)
    {
        printf("A chave precisa ter 26 caracteres! \n");
        return 1;
    }
    for (int u = 0; u < strlen(argv[1]); u++)
    {
        for (int v = u + 1; v < strlen(argv[1]); v++)
        {
            if (toupper(argv[1][u] == toupper(argv[1][v])))
            {
                printf("A chave precisa ter 26 caracteres! \n");
                return 1;
            }
        }
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("A chave só pode ter LETRAS, e deve conter 26 caracteres. \n");
            return 1; // retorna erro
        } // função do ctype.h, verifica se é um digito
    }
    string k = (argv[1]);
    for (int upperkey = 0; upperkey < strlen(argv[1]); upperkey++)
    {
        if (islower(k[upperkey]))
        {
            k[upperkey] = k[upperkey] - 32; // coloca a chave inteira em uppercase
        }
    }

    // pede o texto normal
    printf("successo!\n");
    string texto = get_string("plaintext: ");

    // codifica e printa o texto
    printf("ciphertext: ");
    for (int h = 0; h < strlen(texto); h++)
    {

        if (islower(texto[h]))
        {
            int letra = texto[h] - 97; // armazena o valor da letra na string ex: A é 1 posição, H é
                                       // 8 posição. caso lowercase
            printf(
                "%c",
                k[letra] +
                    32); // trasfere o valor para a chave; exemplo: A(alfabeto) = B(key) - lowercase
        }

        else if (isupper(texto[h]))
        {
            int letra = texto[h] - 65; // caso uppercase
            printf("%c", k[letra]);
        }
        else
            printf("%c", texto[h]);
    }
    printf("\n");
}
