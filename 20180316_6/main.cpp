#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<int> stack;

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
				std::cout << -1 << std::endl;
				return 0;
			}

			int x = 0;
			if (stack.top() == '(')
			{
				stack.pop();
				x = 3;
				if (!stack.empty() && stack.top() != '(')
				{
					int y = stack.top();
					stack.pop();
					x += y;
				}
				stack.push(x);
			}
			else if (stack.size() >= 3 && stack.top() != '(')
			{
				x = stack.top() * 3;
				stack.pop();
				stack.pop();
				if (!stack.empty() && stack.top() != '(')
				{
					int y = stack.top();
					stack.pop();
					x += y;
				}
				stack.push(x);
			}
			else
			{
				std::cout << -1 << std::endl;
				return 0;
			}
		}
	}
	std::cout << stack.top() << std::endl;
	return 0;
}
