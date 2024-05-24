#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int this_is_jpg(unsigned char bytes[]);

int main(int argc, char *argv[])
{
    //checar numero de comandos
 if(argc != 2){
    printf("usage: ./recover archive\n");
    return 1;
 }

    //file opening validation
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Could not open file\n");
        return 2;
    }
    //arquivo de output (por enquanto inexistente)
    FILE *output = NULL;

    //buffer para contagem de bytes em um cartão FAT, char para o nome do arquivo, contagem e variavel para quando for achado um jpg
    unsigned char bytes [512];
    char nomearquivo[10];
    int count = 0;
    while(fread(bytes, 512, 1, file) != 0){
        if(this_is_jpg(bytes) == 1){
            if(output != NULL){
                fclose(output);
            }
            sprintf(nomearquivo, "%03d.jpg", count);
            output = fopen(nomearquivo, "w");
            count++;
        }
        if(output != NULL){
            fwrite(&bytes, 512, 1, output);
        }

    }
    fclose(output);
    fclose(file);




}
int this_is_jpg(unsigned char bytes[]){
    if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && ( bytes[3] >= 0xe0 && bytes[3] <= 0xef)){
        return 1;
    }
    return 0;
}
