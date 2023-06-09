#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, swapcol = width-1; j < width; j++)
        {
            image[i][j] = original[i][swapcol];
            swapcol--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int rowx[] = { i-1, i, i+1 };
            int colx[] = { j-1, j, j+1 };
            float totalR = 0, totalG = 0, totalB = 0;
            for (int row = 0; row < 3; row++)
            {
                for(int col = 0; col < 3; col++)
                {
                    int currow = rowx[row];
                    int curcol = colx[col];
                    if (currow >= 0 && currow < height && curcol >=0 && curcol < width)
                    {
                        RGBTRIPLE pixel = image[currow][curcol];
                        totalR += pixel.rgbtRed;
                        totalG += pixel.rgbtGreen;
                        totalB += pixel.rgbtBlue;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round(totalR / count);
            temp[i][j].rgbtGreen = round(totalG / count);
            temp[i][j].rgbtBlue = round(totalB / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE previous[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            previous[i][j] = image[i][j];
        }
    }
    int gx[3][3] =
    {
        {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}
    };
    int gy[3][3] =
    {
        {-1, -2, -1}, {0, 0, 0}, {1, 2, 1}
    };
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_row[3] = {i-1, i, i+1};
            int new_col[3] = {j-1, j, j+1};
            int xR = 0, xG = 0, xB = 0;
            int yR = 0, yG = 0, yB = 0;
            for (int rowc = 0; rowc < 3; rowc++)
            {
                for (int colc = 0; colc < 3; colc++)
                {
                    int rowx = new_row[rowc];
                    int colx = new_col[colc];
                    RGBTRIPLE pixel = previous[rowx][colx];
                    if (rowx >= 0 && rowx < height && colx >= 0 && colx < width)
                    {
                    xR += pixel.rgbtRed * gx[rowc][colc];
                    xG += pixel.rgbtGreen * gx[rowc][colc];
                    xB += pixel.rgbtBlue * gx[rowc][colc];

                    yR += pixel.rgbtRed * gy[rowc][colc];
                    yG += pixel.rgbtGreen * gy[rowc][colc];
                    yB += pixel.rgbtBlue * gy[rowc][colc];
                    }
                }
            }
            int r = round(sqrt(xR * xR + yR * yR));
            int g = round(sqrt(xG * xG + yG * yG));
            int b = round(sqrt(xB * xB + yB * yB));

            image[i][j].rgbtRed = r > 255? 255: r;
            image[i][j].rgbtGreen = g > 255? 255: g;
            image[i][j].rgbtBlue = b > 255? 255: b;
        }
    }
    return;

}
