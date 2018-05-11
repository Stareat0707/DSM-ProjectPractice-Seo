#include <iostream>

int main()
{
	int row, col;
	std::cin >> row >> col;

	int x = 0;
	int y = row - 1;

	int nowRow = row - 1;
	int nowCol = 0;

	int* nArray = new int[row * col];
	for (int i = 0; i < row * col; ++i)
	{
		nArray[i] = 0;
	}

	for (int i = 1; i <= row * col; ++i)
	{
		nArray[y++ * col + x++] = i;
		if (x == col || y == row)
		{
			x = 0;
			y = --nowRow;
			if (y < 0)
			{
				++y;
				++nowRow;
				while (nArray[y * col + x] != 0)
				{
					++x;
				}
			}
		}
	}

	for (int i = 1; i <= row * col; ++i)
	{
		std::cout << nArray[i - 1];
		if (i % col == 0)
			std::cout << std::endl;
		else
			std::cout << '\t';
	}

	return 0;
}