//importing library and file
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width ; col++)
        {
            float average = (image[row][col].rgbtBlue + image[row][col].rgbtGreen + image[row][col].rgbtRed)/3.00;
            //using round function to make the float into int
            int avg = round(average);


            image[row][col].rgbtGreen = avg;
            image[row][col].rgbtBlue = avg;
            image[row][col].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //using for loop to make column and row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //using round function and formula given we can shape the bites
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue) ;
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue) ;
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue) ;

            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < (width / 2); j++)\
        {
            int red = image[i][j].rgbtRed;;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtBlue = blue;
            image[i][width - j - 1].rgbtGreen = green;


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
//starting to blur pictures
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            //definning int variables
            int sumBlue = 0;
            int sumRed = 0;
            int sumGreen = 0;
            //definning float variable 
            float counter = 0.00;
            for (int k = -1; k < 2; k++)
            {
                for (int h = -1; h < 2 ; h++)
                {
                    // using if statement to build up chart
                    if (i + k < 0 || i + k > height - 1 || j + h < 0 || j + h > width  - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + k][j + h].rgbtBlue;
                    sumRed += image[i + k][j + h].rgbtRed;
                    sumGreen += image[i + k][j + h].rgbtGreen;

                    counter++;

                }
            }
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        //countinue making charts
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
