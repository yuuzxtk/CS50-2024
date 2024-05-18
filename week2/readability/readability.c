#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double l = 0, s = 0, w = 1, L, S;

/*L = 100*l/w;
  S = 100*s/w;
  int index = round(0.0588*L - 0.296*S - 15.8);*/

int contador_de_palavras(string words);
int contador_de_letras(string letters);
int contador_de_sentencas(string sentences);

int main(void)
{
    string text = get_string("digite seu texto aqui: ");
    int letras = contador_de_letras(text); // função contador de letras em ação

    int palavras = contador_de_palavras(text); // função contador de palavras em ação

    int sentencas = contador_de_sentencas(text); // função contador de sentenças em ação

    L = 100 * l / w;
    S = 100 * s / w;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // printar o resultado
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// função para contar as letras das palavras
int contador_de_letras(string letters)
{
    for (int z = 0, n = strlen(letters); z < n; z++)
    {
        if ((letters[z] >= 'a' && letters[z] <= 'z') || (letters[z] >= 'A' && letters[z] <= 'Z'))
        {
            l += 1;
        }
    }
    return l;
}

// retorna o número de palavras do texto
int contador_de_palavras(string words)
{
    for (int x = 0, h = strlen(words); x < h; x++)
    {
        if (words[x] == ' ')
        {
            w += 1;
        }
    }
    return w;
}

// retorna o numero de sentenças do texto
int contador_de_sentencas(string sentences)
{
    for (int y = 0, j = strlen(sentences); y < j; y++)
    {
        if (sentences[y] == '.' || sentences[y] == '!' || sentences[y] == '?')
        {
            s += 1;
        }
    }
    return s;
}
