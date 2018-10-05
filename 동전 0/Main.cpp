#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> A(n);
	for (int i = n - 1; i >= 0; --i)
		cin >> A[i];
	
	int result = 0;
	for (int i = 0; k > 0; ++i)
	{
		if (k / A[i] > 0)
		{
			result += k / A[i];
			k %= A[i];
		}
	}

	cout << result << endl;
	return 0;
}
