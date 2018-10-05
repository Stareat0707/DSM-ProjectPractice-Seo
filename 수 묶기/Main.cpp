#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> pArr;
	vector<int> nArr;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;

		if (m > 0)
			pArr.push_back(m);
		else
			nArr.push_back(m);
	}
	
	sort(pArr.rbegin(), pArr.rend());
	sort(nArr.begin(), nArr.end());

	int result = 0;
	for (int i = 0; i < pArr.size(); ++i)
	{
		if (i < pArr.size() - 1 && pArr[i] != 1 && pArr[i + 1] != 1)
		{
			result += pArr[i] * pArr[i + 1];
			++i;
		}
		else
			result += pArr[i];
	}

	for (int i = 0; i < nArr.size(); ++i)
	{
		if (i < nArr.size() - 1)
		{
			result += nArr[i] * nArr[i + 1];
			++i;
		}
		else
			result += nArr[i];
	}

	cout << result << endl;	
	return 0;
}
