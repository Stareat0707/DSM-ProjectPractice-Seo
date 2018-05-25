#include <iostream>

int main()
{
	int row, col;
	std::cin >> row >> col;

	int x = col - 1;
	int y = 0;

	int nowRow = 0;
	int nowCol = col - 1;

	int* nArray = new int[row * col];
	for (int i = 0; i < row * col; ++i)
	{
		nArray[i] = 0;
	}

	for (int i = 1; i <= row * col; ++i)
	{
		nArray[y-- * col + x--] = i;
		if (x < 0 || y < 0)
		{
			x = col - 1;
			y = ++nowRow;
			if (y >= row)
			{
				--y;
				--nowRow;
				x = --nowCol;
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