#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<char> stack;

	std::string input;
	std::cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		char c = input.at(i);
		switch (c)
		{
		case '(':
			stack.push(c);
			break;
		case ')':
			if (stack.empty())
			{
				std::cout << "NO" << std::endl;
				return 0;
			}
			if (stack.top() == '(')
				stack.pop();
			else
			{
				std::cout << "NO" << std::endl;
				return 0;
			}
		}
	}

	if (stack.empty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}
