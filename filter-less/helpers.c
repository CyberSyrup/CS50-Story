#include "helpers.h"
#include <math.h>

int min(double a, double b);
void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // So I think only about the task not about the whole structure

            // Getting the original colours
            double originalRed = image[i][j].rgbtRed;
            double originalGreen = image[i][j].rgbtGreen;
            double originalBlue = image[i][j].rgbtBlue;

            // Calculating sepia colours
            double sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            double sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            double sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // Round up and cap
            sepiaRed = min(255, round(sepiaRed));
            sepiaGreen = min(255, round(sepiaGreen));
            sepiaBlue = min(255, round(sepiaBlue));

            // Updating the pixels
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // We need to use pixels only from one side until the middle of it
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Looping through the original image vertically
    for (int i = 0; i < height; i++)
    {
        // Looping through the original image horizontally
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            // This looks up and down
            for (int ni = -1; ni <= 1; ni++)
            {
                // This looks left and right
                for (int nj = -1; nj <= 1; nj++)
                {
                    int ni_n = i + ni;
                    int nj_n = j + nj;

                    // Checking if it's not over the boundaries
                    if (ni_n >= 0 && ni_n < height && nj_n >= 0 && nj_n < width)
                    {
                        // Update the sum of color values
                        sumRed += copy[ni_n][nj_n].rgbtRed;
                        sumGreen += copy[ni_n][nj_n].rgbtGreen;
                        sumBlue += copy[ni_n][nj_n].rgbtBlue;

                        // Increment the count of neighboring pixels
                        count++;
                    }
                }
            }

            // Calculate the average color values
            int avgRed = round((float) sumRed / count);
            int avgGreen = round((float) sumGreen / count);
            int avgBlue = round((float) sumBlue / count);

            // Update the original pixel with the averaged color values
            image[i][j].rgbtRed = avgRed;
            image[i][j].rgbtGreen = avgGreen;
            image[i][j].rgbtBlue = avgBlue;
        }
    }

    return;
}

// function for finding the least one
int min(double a, double b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// function for swaping the two sides
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    // Declaring the temp function like a third cup
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
}
