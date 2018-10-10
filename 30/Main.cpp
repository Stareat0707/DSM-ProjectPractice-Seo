#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isAnswer(string s)
{
	string n = "0" + s;

	for (int i = 1; i < n.size(); ++i)
	{
		int x = stoi(n.substr(i - 1, 2));
		n[i - 1] = '0';
		n[i] = x % 3 + 48;
	}

	if (n.back() == '0')
		return true;
	else
		return false;
}

int main()
{
	string n;
	cin >> n;

	size_t idx = n.find('0');
	if (idx == string::npos)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		n.erase(idx, 1);
		sort(n.rbegin(), n.rend());

		if (isAnswer(n))
			cout << n + "0" << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}
