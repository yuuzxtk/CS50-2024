#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
        {
            int colorgray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            if (colorgray > 255){
                colorgray = 255;
            }
            image[i][j].rgbtRed = colorgray;
            image[i][j].rgbtGreen = colorgray;
            image[i][j].rgbtBlue = colorgray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiared = 0;
    int sepiagreen = 0;
    int sepiablue = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sepiared = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiagreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiablue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

        if (sepiared > 255)
        {
            sepiared = 255;
        }
        if (sepiagreen > 255){
            sepiagreen = 255;
        }
        if (sepiablue > 255){
            sepiablue = 255;
        }
        image[i][j].rgbtBlue = sepiablue;
        image[i][j].rgbtGreen = sepiagreen;
        image[i][j].rgbtRed = sepiared;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float red;
    float green;
    float blue;
    float counter = 0.0;
    RGBTRIPLE tmp[height][width];
     for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            tmp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            tmp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][j].rgbtRed = image[i][j].rgbtRed;
        }
     }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            red=green=blue = 0;
            counter=0;
                if (i - 1 >= 0)
            {
                red += tmp[i - 1][j].rgbtRed;
                green += tmp[i - 1][j].rgbtGreen;
                blue += tmp[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i + 1 < height)
            {
                red += tmp[i + 1][j].rgbtRed;
                green += tmp[i + 1][j].rgbtGreen;
                blue += tmp[i + 1][j].rgbtBlue;
                counter++;
            }
            if (j - 1 >= 0)
            {
                red += tmp[i][j - 1].rgbtRed;
                green += tmp[i][j - 1].rgbtGreen;
                blue += tmp[i][j - 1].rgbtBlue;
                counter++;
            }
            if (j + 1 < width)
            {
                red += tmp[i][j + 1].rgbtRed;
                green += tmp[i][j + 1].rgbtGreen;
                blue += tmp[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += tmp[i - 1][j - 1].rgbtRed;
                green += tmp[i - 1][j - 1].rgbtGreen;
                blue += tmp[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                red += tmp[i + 1][j + 1].rgbtRed;
                green += tmp[i + 1][j + 1].rgbtGreen;
                blue += tmp[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                red += tmp[i + 1][j - 1].rgbtRed;
                green += tmp[i + 1][j - 1].rgbtGreen;
                blue += tmp[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += tmp[i - 1][j + 1].rgbtRed;
                green += tmp[i - 1][j + 1].rgbtGreen;
                blue += tmp[i - 1][j + 1].rgbtBlue;
                counter++;
            }
                red += tmp[i][j].rgbtRed;
                green += tmp[i][j].rgbtGreen;
                blue += tmp[i][j].rgbtBlue;
                counter++;

                    image[i][j].rgbtBlue = round(blue/(counter * 1.0));
                    image[i][j].rgbtGreen = round(green/(counter * 1.0));
                    image[i][j].rgbtRed = round(red/(counter * 1.0));

                    red = 0;
                    blue = 0;
                    green = 0;
                    counter = 0;

                }


    }
return;
        }

