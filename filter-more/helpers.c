#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int clr = round((image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = clr;
            image[i][j].rgbtGreen = clr;
            image[i][j].rgbtBlue = clr;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2; j++) //as per the previous hw we are only interacting with half the image so width/2
        {
            RGBTRIPLE stor = image[i][j]; //stores the original location of the left half pixel
            image[i][j] = image[i][width-j-1]; //as we want to make the left half pixel into the rite half so we must slowly interate from the back of the array using width-j-1 we can start itreating from the last array
            image[i][width-j-1] = stor;
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
        for(int j = 0; j < width; j++) //as per the previous hw we are only interacting with half the image so width/2
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++) //as per the previous hw we are only interacting with half the image so width/2
        {
            int red_sum = 0;
        int blue_sum = 0;
        int green_sum = 0;
        float counter = 0.00;
            for(int x = -1; x < 2; x++)
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
                    blue_sum += image[row][column].rgbtBlue;
                    green_sum += image[row][column].rgbtGreen;
                    counter += 1;
                }
            }
            copy[i][j].rgbtRed = round(red_sum/counter);
            copy[i][j].rgbtBlue = round(blue_sum/counter);
            copy[i][j].rgbtGreen = round(green_sum/counter);
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++) //as per the previous hw we are only interacting with half the image so width/2
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];
    int kernel_x[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int kernel_y[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++) //as per the previous hw we are only interacting with half the image so width/2
        {
            int gx_red = 0;
            int gx_blue = 0;
            int gx_green = 0;
            int gy_red = 0;
            int gy_blue = 0;
            int gy_green = 0;
            for(int x = -1; x < 2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    int row = i + x;
                    int column = j + y;
                    if(row < 0 || row > height-1 || column < 0 || column > width-1)
                    {
                        continue;
                    }
                    gx_red += image[row][column].rgbtRed*kernel_x[x+1][y+1];
                    gy_red += image[row][column].rgbtRed*kernel_y[x+1][y+1];
                    gx_blue += image[row][column].rgbtBlue*kernel_x[x+1][y+1];
                    gy_blue += image[row][column].rgbtBlue*kernel_y[x+1][y+1];
                    gx_green += image[row][column].rgbtGreen*kernel_x[x+1][y+1];
                    gy_green += image[row][column].rgbtGreen*kernel_y[x+1][y+1];
                }
            }
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));

            copy[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            copy[i][j].rgbtGreen = (green > 255) ? 255 : green;
            copy[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++) //as per the previous hw we are only interacting with half the image so width/2
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
