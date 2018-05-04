#include <iostream>

int function(int input)
{
	if (input <= 1)
		return 1;

	int result = 0;

	for (int root = 1; root <= input; ++root)
	{
		int leftCount = 0;
		for (int j = 1; j < root; ++j)
		{
			++leftCount;
		}

		int rightCount = 0;
		for (int j = root + 1; j <= input; ++j)
		{
			++rightCount;
		}

		result += function(leftCount) * function(rightCount);
	}

	return result;
}

int main()
{
	for (int i = 1; i <= 8; ++i)
	{
		std::cout << function(i) << std::endl;
	}

	return 0;
}