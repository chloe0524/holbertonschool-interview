#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - prints 3x3 grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: 1st sandpile
 * @grid2: 2nd sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int sand, grains;
    int falling_sand;

    for (sand = 0; sand < 3; sand++)
    {
        for (grains = 0; grains < 3; grains++)
        {
            grid1[sand][grains] += grid2[sand][grains];
        }
    }
    print_grid(grid1);

    do {
        falling_sand = 0;
        int temp[3][3] = {0};

        for (sand = 0; sand < 3; sand++)
        {
            for (grains = 0; grains < 3; grains++)
            {
                if (grid1[sand][grains] >= 4)
                {
                    falling_sand = 1;
                    temp[sand][grains] -= 4;
                    if (sand > 0) temp[sand - 1][grains]++;
                    if (sand < 2) temp[sand + 1][grains]++;
                    if (grains > 0) temp[sand][grains - 1]++;
                    if (grains < 2) temp[sand][grains + 1]++;
                }
            }
        }
        for (sand = 0; sand < 3; sand++)
        {
            for (grains = 0; grains < 3; grains++)
            {
                grid1[sand][grains] += temp[sand][grains];
            }
        }
        falling_sand ? print_grid(grid1) : (void)0;
    } while (falling_sand);
}