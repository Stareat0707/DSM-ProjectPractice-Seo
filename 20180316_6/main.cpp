#include <iostream>
#include <stack>
#include <string>

bool function(std::stack<int>& stack, int num)
{
	if (stack.empty())
	{
		std::cout << -1 << std::endl;
		return false;
	}

	if (stack.top() == '(' || stack.top() == '[')
	{
		stack.pop();
		int x = num;
		if (!stack.empty() && stack.top() != '(' && stack.top() != '[')
		{
			int y = stack.top();
			stack.pop();
			x += y;
		}
		stack.push(x);
	}
	else if (stack.size() >= num && stack.top() != '(' && stack.top() != '[')
	{
		int x = stack.top() * num;
		stack.pop();
		stack.pop();
		if (!stack.empty() && stack.top() != '(' && stack.top() != '[')
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
		return false;
	}

	return true;
}

int main()
{
	std::stack<int> stack;

	std::string input;
	std::cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		char c = input.at(i);
		int x;
		switch (c)
		{
		case '(':
		case '[':
			stack.push(c);
			break;
		case ')':
			if (!function(stack, 2))
				return 0;
			break;
		case ']':
			if (!function(stack, 3))
				return 0;
			break;
		}
	}
	std::cout << stack.top() << std::endl;
	return 0;
}
