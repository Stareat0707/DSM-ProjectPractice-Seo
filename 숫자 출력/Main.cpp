#include <iostream>

// y * width + x
// width + 1

int main()
{
	int width, height;
	std::cin >> height >> width;
	int arrayLength = width * height;

	int* numArray = new int[arrayLength];

	for (int i = 0; i < arrayLength; ++i)
	{
		numArray[i] = 0;
	}
	int position = width * (height - 1);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << numArray[i * width + j] << '\t';
		}
		std::cout << std::endl;
	}

	delete[] numArray;
	numArray = NULL;

	return 0;
}