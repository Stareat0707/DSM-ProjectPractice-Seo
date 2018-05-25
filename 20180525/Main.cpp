#include <iostream>
#include <vector>

int main()
{
	int row, col;
	std::cin >> row >> col;

	std::vector<int> indices;

	int mapSize = row * col;
	int* nArray = new int[mapSize];
	for (int i = 0; i < mapSize; ++i)
	{
		std::cin >> nArray[i];
		if (nArray[i] == 1)
			indices.push_back(i);
	}
	while (!indices.empty())
	{
		bool flag = false;
		std::vector<int> nextIndices;
		for (auto& i : indices)
		{
			if (i >= col && nArray[i - col] == 0)
			{
				nArray[i - col] = nArray[i] + 1;
				nextIndices.push_back(i - col);
			}
			if (i + col < mapSize && nArray[i + col] == 0)
			{
				nArray[i + col] = nArray[i] + 1;
				nextIndices.push_back(i + col);
			}
			if ((i + 1) % col != 0 && nArray[i + 1] == 0)
			{
				nArray[i + 1] = nArray[i] + 1;
				nextIndices.push_back(i + 1);
			}
			if (i % col != 0 && nArray[i - 1] == 0)
			{
				nArray[i - 1] = nArray[i] + 1;
				nextIndices.push_back(i - 1);
			}
		}

		indices = nextIndices;
	}

	for (int i = 0; i < mapSize; ++i)
	{
		std::cout.width(2);
		std::cout << nArray[i] << ' ';
		if (i % col == col - 1)
			std::cout << std::endl;
	}
	return 0;
}
