#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //handling one pixel only
            int originalRed = image[h][w].rgbtRed;
            int originalGreen = image[h][w].rgbtGreen;
            int originalBlue = image[h][w].rgbtBlue;

            // avergage of the these colors
            int averageColor = round((originalRed +  originalGreen +  originalBlue) / 3.0);

            image[h][w].rgbtRed = averageColor;
            image[h][w].rgbtGreen = averageColor;
            image[h][w].rgbtBlue = averageColor;


        }
    }

    // image[0][0].rgbtRed = 0;
    return;
}

int moreThan255(int channel)
{
    if (channel > 255)
    {
        channel = 255;
    }
    return channel;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sRed;
    int sGreen;
    int sBlue;

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //handling one pixel only
            int originalRed = image[h][w].rgbtRed;
            int originalGreen = image[h][w].rgbtGreen;
            int originalBlue = image[h][w].rgbtBlue;

            // Converting to Sepia of the these colors

            sRed = moreThan255(round(.393 *  originalRed + .769 *  originalGreen + .189 *  originalBlue));
            sGreen = moreThan255(round(.349 *  originalRed + .686 *  originalGreen + .168 *  originalBlue));
            sBlue = moreThan255(round(.272 * originalRed + .534 *  originalGreen + .131 *  originalBlue));

            image[h][w].rgbtRed = sRed;
            image[h][w].rgbtGreen = sGreen;
            image[h][w].rgbtBlue = sBlue;


            // if (image[h][w].rgbtRed > 255)
            // {
            //     image[h][w].rgbtRed = 255;
            // }

            // if (image[h][w].rgbtGreen > 255)
            // {
            //     image[h][w].rgbtGreen = 255;
            // }

            // if (image[h][w].rgbtBlue > 255)
            // {
            //     image[h][w].rgbtBlue = 255;
            // }

            // if (image[h][w].rgbtRed < 0)
            // {
            //     image[h][w].rgbtRed = 0;
            // }

            // if (image[h][w].rgbtGreen < 0)
            // {
            //     image[h][w].rgbtGreen = 0;
            // }

            // if (image[h][w].rgbtBlue < 0)
            // {
            //     image[h][w].rgbtBlue = 0;
            // }

        }
    }

    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp_loc[3];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            //store half the pixels in temp location
            temp_loc[0] = image[h][w].rgbtRed ;
            temp_loc[1] = image[h][w].rgbtGreen ;
            temp_loc[2] = image[h][w].rgbtBlue ;

            image[h][w].rgbtRed = image[h][width - 1 - w].rgbtRed ;
            image[h][w].rgbtGreen = image[h][width - 1 - w].rgbtGreen ;
            image[h][w].rgbtBlue = image[h][width - 1 - w].rgbtBlue ;

            // copy the temp to the left
            image[h][width - 1 - w].rgbtRed = temp_loc[0];
            image[h][width - 1 - w].rgbtGreen = temp_loc[1];
            image[h][width - 1 - w].rgbtBlue = temp_loc[2];


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // create a temp image from the original
    RGBTRIPLE temp_pic[height][width];


    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // nearest rows and cols
            int counter = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            for (int r = h - 1; r < (h + 2); r++)
            {
                for (int c = w - 1; c < (w + 2); c++)
                {
                    // Checks for the edge cases - only non-edge cases used here
                    if (r < 0 || r >= height || c < 0 || c >= width )
                    {
                        continue;
                    }
                    else
                    {
                        sumRed = sumRed + image[r][c].rgbtRed ;
                        sumGreen = sumGreen + image[r][c].rgbtGreen ;
                        sumBlue = sumBlue + image[r][c].rgbtBlue ;

                        counter++;
                    }
                    // store in temp image
                    temp_pic[h][w].rgbtRed = round(sumRed / counter);
                    temp_pic[h][w].rgbtGreen = round(sumGreen / counter);
                    temp_pic[h][w].rgbtBlue = round(sumBlue /counter);

                }
            }



        }
    }

    //paset the temp image to original
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = temp_pic[h][w].rgbtRed;
            image[h][w].rgbtGreen = temp_pic[h][w].rgbtGreen;
            image[h][w].rgbtBlue = temp_pic[h][w].rgbtBlue;
        }
    }


    return;
}
