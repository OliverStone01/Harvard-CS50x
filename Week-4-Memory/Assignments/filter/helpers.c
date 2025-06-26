#include "helpers.h"
#include <math.h>
#include <stdio.h>

int check(int input);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtBlue = a;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    // create a temporary image array to store data.
    RGBTRIPLE temp[height][width];

    // loop through the original image copying the data to the temp array.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            sepiaRed = round(.393 * temp[i][j].rgbtRed + .769 * temp[i][j].rgbtGreen + .189 * temp[i][j].rgbtBlue);
            sepiaGreen = round(.349 * temp[i][j].rgbtRed + .686 * temp[i][j].rgbtGreen + .168 * temp[i][j].rgbtBlue);
            sepiaBlue = round(.272 * temp[i][j].rgbtRed + .534 * temp[i][j].rgbtGreen + .131 * temp[i][j].rgbtBlue);

            image[i][j].rgbtRed = check(sepiaRed);
            image[i][j].rgbtGreen = check(sepiaGreen);
            image[i][j].rgbtBlue = check(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create a temporary image array to store data.
    RGBTRIPLE temp[height][width];

    // loop through the original image copying the data to the temp array.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][(width - 1) - j];
            image[i][j] = temp[i][(width - 1) - j];
            image[i][j] = temp[i][(width - 1) - j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create integers to store temporary data.
    // And a double for the counter.
    int R = 0;
    int G = 0;
    int B = 0;
    double count = 0;

    // create a temporary image array to store data.
    RGBTRIPLE temp[height][width];

    // loop through the original image copying the data to the temp array.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    // loop through the image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // reset the count and integers to 0.
            R = 0;
            G = 0;
            B = 0;
            count = 0;
            // loop through the height, hight - 1, and height + 1.
            for (int k = (i - 1); k < (i + 2); k++)
            {
                // if k is inside 0 and height.
                if (k >= 0 && k < height)
                {
                    // loop through the width, width - 1, and width + 1.
                    for (int l = (j - 1); l < (j + 2); l++)
                    {
                        // if l is inside of 0 and width.
                        if (l >= 0 && l < width)
                        {
                            // collect data and up the cound
                            R = R + image[k][l].rgbtRed;
                            G = G + image[k][l].rgbtGreen;
                            B = B + image[k][l].rgbtBlue;
                            count ++;
                        }
                    }
                }
            }
            // set the temp array to rounded ints of the data divided by the count.
            temp[i][j].rgbtRed = round(R / count);
            temp[i][j].rgbtGreen = round(G / count);
            temp[i][j].rgbtBlue = round(B / count);
        }
    }
    // copy the temp image to image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

int check(int input)
{
    if (input < 0)
    {
        return 0;
    }
    else if (input > 255)
    {
        return 255;
    }
    else
    {
        return input;
    }
}
