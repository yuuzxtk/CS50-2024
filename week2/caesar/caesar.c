#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, string argv[]){
    if (argc != 2){ //só aceita comandos de um periodo
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //validar a key
    string k = argv[1];
    for(int i = 0; i < strlen(argv[1]); i++){
        if(!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;  //retorna erro
        } //função do ctype.h, verifica se é um digito. o ! na frente traz o resultado contrário, ou seja, só letras
    }
    printf("Success\n%s\n", k);

    string get_text = get_string("plaintext: ");
    printf("ciphertext: ");
    //criptografar e printar
    for(int h = 0; h < strlen(get_text); h++){
        if(isupper(get_text[h])){
            printf("%c", (((int)get_text[h] + atoi(k) - 65) %26 + 65));
        }
        else if (islower(get_text[h])){
             printf("%c", (((int)get_text[h] + atoi(k) - 97) %26 + 97));
        }
        else{
            printf("%c", get_text[h]);
        }
    } printf("\n");

}

