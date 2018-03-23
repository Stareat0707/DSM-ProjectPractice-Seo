#include <iostream>
#include <stack>
#include <string>

void popAll(std::stack<char>& stack)
{
	while (!stack.empty())
	{
		std::cout << stack.top();
		stack.pop();
	}
}

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
		case '+':
		case '-':
		case '*':
		case '/':
			if (!stack.empty())
			{
				char top = stack.top();
				if (((top != '+' && top != '-') || (c != '*' && c != '/')) && top != '(')
					popAll(stack);
			}
			stack.push(c);
			break;
		case '(':
			stack.push(c);
			break;
		case ')':
			while (stack.top() != '(')
			{
				std::cout << stack.top();
				stack.pop();
			}
			stack.pop();
			break;
		default:
			std::cout << input.at(i);
		}
	}

	popAll(stack);

	std::cout << std::endl;
	return 0;
}
