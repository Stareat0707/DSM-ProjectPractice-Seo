#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> vector;
	for (int i = 0; i < N; ++i)
	{
		int n;
		std::cin >> n;
		vector.push_back(n);
	}

	int count = 0;
	while (vector.size() >= 2)
	{
		std::sort(vector.rbegin(), vector.rend());

		int temp = vector.back();
		vector.pop_back();
		temp += vector.back();
		vector.pop_back();
		vector.push_back(temp);
		count += temp;
	}

	std::cout << count << std::endl;
	return 0;
}
