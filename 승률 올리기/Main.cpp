#include <iostream>
#include <cmath>

int main()
{
	int N = 0;
	std::cin >> N;

	int M = 0;
	std::cin >> M;

	int odds = (double)M / (double)N * 100;

	if (odds++ >= 99)
		std::cout << -1 << std::endl;
	else
	{
		int result = std::ceil((double)(odds * N - 100 * M) / (double)(100 - odds));
		std::cout << result << std::endl;
	}
	return 0;
}
