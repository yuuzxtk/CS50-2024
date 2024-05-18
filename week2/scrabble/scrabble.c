#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculo_score(string word);
int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // de A a Z

// obtêm as palavras usadas no jogo por cada jogador
int main(void)
{
    string word1 = get_string("player 1 word: ");
    string word2 = get_string("player 2 word: ");

    int score1 = calculo_score(word1);
    int score2 = calculo_score(word2);

    if (score1 > score2)
    {
        printf("player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// registra as letras, suas pontuações e coloca em uma variavel

int calculo_score(string word)
{
    int score = 0;
    for (int x = 0, len = strlen(word); x < len; x++)
    {
        if (isupper(word[x]))
        {
            score += POINTS[word[x] - 'A'];
        }
        else if (islower(word[x]))
        {
            score += POINTS[word[x] - 'a'];
        }
    }
    return score;
}
