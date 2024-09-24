#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int sand, grains;
	int falling_sand = 0;

	for (sand = 0; sand < 3; sand++)
	{
		for (grains = 0; grains < 3; grains++)
		{
			grid1[sand][grains] += grid2[sand][grains];
		}
	}

	while (falling_sand != 1)
	{
		falling_sand = 1;
		int temp[3][3] = {0};

		for (sand = 0; sand < 3; sand++)
		{
			for (grains = 0; grains < 3; grains++)
			{
				if (grid1[sand][grains] >= 4)
				{
					falling_sand = 0;
					temp[sand][grains] -= 4;
					temp[sand > 0 ? sand - 1 : sand][grains] += (sand > 0) ? 1 : 0;
					temp[sand < 2 ? sand + 1  : sand][grains] += (sand < 2) ? 1 : 0;
					temp[sand][grains > 0 ? grains - 1 : grains] += (grains > 0) ? 1 : 0;
					temp[sand][grains < 2 ? grains + 1 : grains] += (grains < 2) ? 1 : 0;
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
	}
}
