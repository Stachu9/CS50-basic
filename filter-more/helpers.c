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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
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

            int counter = 0;

            int avRed = 0;
            int avGreen = 0;
            int avBlue = 0;

            for (int z = zMin; z <= zMax; z++)
            {
                for (int x = xMin; x <= xMax; x++)
                {
                    avRed += image[z][x].rgbtRed;
                    avGreen += image[z][x].rgbtGreen;
                    avBlue += image[z][x].rgbtBlue;
                    counter ++;
                    //printf("coordinates: %i, %i. Blue: %i, avBlue: %i, Counter: %i\n", z, x, image[z][x].rgbtBlue, avBlue, counter);
                }
            }
            tempImage[i][j].rgbtRed = round(avRed / counter);
            tempImage[i][j].rgbtGreen = round(avGreen / counter);
            tempImage[i][j].rgbtBlue = round(avBlue / counter);
        }
    }

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
    RGBTRIPLE tempImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
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

            int counter = 0;

            int avRed = 0;
            int avGreen = 0;
            int avBlue = 0;

            RGBTRIPLE tempCalcX[3][3];
            RGBTRIPLE tempCalcY[3][3];

            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    tempCalcX[k][l].rgbtRed = 0;
                    tempCalcX[k][l].rgbtGreen = 0;
                    tempCalcX[k][l].rgbtBlue = 0;

                    tempCalcY[k][l].rgbtRed = 0;
                    tempCalcY[k][l].rgbtGreen = 0;
                    tempCalcY[k][l].rgbtBlue = 0;
                }
            }

            int gxTempRed = 0;
            int gxTempGreen = 0;
            int gxTempBlue = 0;
            int tempZ = 0;
            int tempX = 0;

            for (int z = zMin; z <= zMax; z++)
            {
                for (int x = xMin; x <= xMax; x++)
                {
                    //GxArr
                    if (x < j && z != i)
                    {
                        tempCalcX[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * -1;
                        tempCalcX[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * -1;
                        tempCalcX[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * -1;
                    }
                    else if (x < j && z == i)
                    {
                        tempCalcX[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * -2;
                        tempCalcX[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * -2;
                        tempCalcX[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * -2;
                    }
                    else if (x == j)
                    {
                        tempCalcX[tempZ][tempX].rgbtRed = 0;
                        tempCalcX[tempZ][tempX].rgbtGreen = 0;
                        tempCalcX[tempZ][tempX].rgbtBlue = 0;
                    }
                    if (x > j && z != i)
                    {
                        tempCalcX[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * 1;
                        tempCalcX[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * 1;
                        tempCalcX[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * 1;
                    }
                    else if (x > j && z == i)
                    {
                        tempCalcX[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * 2;
                        tempCalcX[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * 2;
                        tempCalcX[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * 2;
                    }

                    //GyArr
                    if (z < i && x != j)
                    {
                        tempCalcY[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * -1;
                        tempCalcY[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * -1;
                        tempCalcY[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * -1;
                    }
                    else if (z < i && x == j)
                    {
                        tempCalcY[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * -2;
                        tempCalcY[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * -2;
                        tempCalcY[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * -2;
                    }
                    else if (z == i)
                    {
                        tempCalcY[tempZ][tempX].rgbtRed = 0;
                        tempCalcY[tempZ][tempX].rgbtGreen = 0;
                        tempCalcY[tempZ][tempX].rgbtBlue = 0;
                    }
                    if (z > i && x != j)
                    {
                        tempCalcY[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * 1;
                        tempCalcY[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * 1;
                        tempCalcY[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * 1;
                    }
                    else if (z > i && x == j)
                    {
                        tempCalcY[tempZ][tempX].rgbtRed = image[z][x].rgbtRed * 2;
                        tempCalcY[tempZ][tempX].rgbtGreen = image[z][x].rgbtGreen * 2;
                        tempCalcY[tempZ][tempX].rgbtBlue = image[z][x].rgbtBlue * 2;
                    }

                    tempX ++
                }

                tempZ ++;
            }

            tempImage[i][j].rgbtRed = round(avRed / counter);
            tempImage[i][j].rgbtGreen = round(avGreen / counter);
            tempImage[i][j].rgbtBlue = round(avBlue / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}
