#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avarage = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3);
            image[i][j].rgbtBlue = avarage;
            image[i][j].rgbtGreen = avarage;
            image[i][j].rgbtRed = avarage;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halfWidth = floor(width/2);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfWidth; j++)
        {
            RGBTRIPLE temp = image[i][width - 1 - j];
            image[i][width - 1 - j] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int zMin = i - 1;
            if (zMin < 0)
            {
                zMin = 0;
            }

            int zMax = i + 1;
            if (zMax >= height)
            {
                zMax = height - 1;
            }

            int xMin = j - 1;
            if (xMin < 0)
            {
                xMin = 0;
            }

            int xMax = j + 1;
            if (xMax >= width)
            {
                xMax = width - 1;
            }

            BYTE counter = 0;

            BYTE avRed = 0;
            BYTE avGreen = 0;
            BYTE avBlue = 0;

            for (int z = zMin; z <= zMax; z++)
            {
                for (int x = xMin; x <= xMax; x++)
                {
                    avRed += image[z][x].rgbtRed;
                    avGreen += image[z][x].rgbtGreen;
                    avBlue += image[z][x].rgbtBlue;
                    counter ++;
                    printf("coordinates: %i, %i. Blue: %i, avBlue: %i, Counter: %i\n", z, x, image[z][x].rgbtBlue, avBlue, counter);
                }
            }
            tempImage[i][j].rgbtRed = round(avRed / counter);
            tempImage[i][j].rgbtGreen = round(avGreen / counter);
            tempImage[i][j].rgbtBlue = round(avBlue / counter);
        }
    }

    BYTE h = 500;
    BYTE k = 800;
    BYTE w = h + k;
    printf("%i\n", w);


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
