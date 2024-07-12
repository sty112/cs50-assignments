#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int clr = round((image[i][j].rgbtRed+image[i][j].rgbtBlue+image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtRed = clr;
            image[i][j].rgbtBlue = clr;
            image[i][j].rgbtGreen = clr;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if(sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if(sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if(sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if(sepiaRed < 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if(sepiaGreen < 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if(sepiaBlue < 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2; j++) //width/2 is because we are changing position witht the other half so we only need half to interact with
        {
            RGBTRIPLE stor_1 = image[i][j]; //stores the location of the first pixel
            image[i][j] = image[i][width-j-1]; //width-j-1 because we want the first pixel to become the last pixel and slowly iterate one by one and -1 is because array starts from 0
            image[i][width-j-1] = stor_1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int red_sum = 0;
            int green_sum = 0;
            int blue_sum = 0;
            float counter = 0.00;
            for(int x= -1; x < 2; x++) // as we want to check from the column left tot the pixel to the rite so we use i-1(left) and iterate to i+1(right)
            {
                for(int y = -1; y < 2; y++)
                {
                    int row = i + x;
                    int column = j + y;
                    if(row < 0 || row > (height-1) || column < 0 || column > (width-1))
                    {
                        continue;
                    }
                    red_sum += image[row][column].rgbtRed;
                    green_sum += image[row][column].rgbtGreen;
                    blue_sum += image[row][column].rgbtBlue;
                    counter += 1;
                }
            }
            copy[i][j].rgbtRed = round(red_sum/counter);
            copy[i][j].rgbtGreen = round(green_sum/counter);
            copy[i][j].rgbtBlue = round(blue_sum/counter);
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
