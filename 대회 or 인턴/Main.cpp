#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int  n, m, k;
	cin >> n >> m >> k;

	int team = min(n / 2, m);
	int remain = n - 2 * team + m - team;

	if (k > remain)
	{
		k -= remain;
		remain = 0;

		while (remain < k)
		{
			--team;
			remain += 3;
		}
	}

	cout << team << endl;
	return 0;
}
